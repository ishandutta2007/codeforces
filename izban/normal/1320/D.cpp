#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

vector<int> get_pr(string s) {
    int n = s.length();
    vector<int> pr(n);
    for (int i = 1; i < n; i++) {
        pr[i] = pr[i - 1];
        while (pr[i] && s[pr[i]] != s[i]) pr[i] = pr[pr[i] - 1];
        pr[i] += s[i] == s[pr[i]];
    }
    return pr;
}

struct sparse {
    int n, k;
    vector<int> lg;
    vector<vector<int>> mn;

    sparse() {}
    sparse(vector<int> a) {
        n = a.size();
        lg.resize(n + 1);
        lg[0] = -1;
        for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;

        k = 0;
        while ((1 << k) <= n) k++;

        mn.assign(k, vector<int>(n));
        mn[0] = a;
        for (int i = 1; i < k; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int get(int l, int r) const {
        int t = lg[r - l + 1];
        return min(mn[t][l], mn[t][r - (1 << t) + 1]);
    }
};

pair<vector<int>, vector<int>> buildSufArray(vector<int> s) {
    int n = s.size();
    int sigma = *max_element(s.begin(), s.end()) + 1;
    vector<int> cnt(max(sigma, n));
    vector<int> p(n), pn(n), c(n), cn(n), o(n), lcp(n);

    for (int i = 0; i < n; i++) cnt[(int)s[i]]++;
    for (int i = 1; i < sigma; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) p[--cnt[s[i]]] = i;
    int cl = 1;
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        cl += s[p[i]] != s[p[i - 1]];
        c[p[i]] = cl - 1;
    }

    for (int len = 1; len < n; len <<= 1) {
        cnt.assign(cl, 0);
        for (int i = 0; i < n; i++) cnt[c[i]]++;
        for (int i = 1; i < cl; i++) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++) pn[i] = (p[i] - len + n) % n;
        for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
        cl = 1;
        cn[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            cl += c[p[i]] != c[p[i - 1]] || c[(p[i] + len) % n] != c[(p[i - 1] + len) % n];
            cn[p[i]] = cl - 1;
        }
        c.swap(cn);
    }

    for (int i = 0; i < n; i++) o[p[i]] = i;

    int z = 0;
    for (int i = 0; i < n; i++) {
        int j = o[i];
        if (j == n - 1) {
            z = 0;
        } else {
            while (s[i + z] == s[p[j + 1] + z]) z++;
        }
        lcp[j] = z;
        z -= !!z;
    }
    return {p, lcp};
}

pair<vector<int>, vector<int>> buildSufArray(string s) {
    vector<int> a(s.length());
    for (int i = 0; i < (int)s.length(); i++) a[i] = s[i];
    return buildSufArray(a);
}

int cnt1 = 0, cnt2 = 0;

struct str_util {
    string s;                    // string
    vector<vector<int>> pr;      // prefix function
    vector<int> sarr;            // suffix array
    vector<int> sarr_inv;        // inverse suffix array
    sparse mn;                   // sparse table on lcp

    str_util() {}
    str_util(string _s) {
        s = _s + '#';
        int m = _s.length();

        auto cpr = get_pr(_s);

        int k = 0;
        while ((1 << k) <= m) k++;

        pr.assign(k, vector<int>(m + 1));
        cpr.insert(cpr.begin(), 0);
        pr[0] = cpr;
        for (int i = 1; i < k; i++) {
            for (int j = 0; j <= m; j++) {
                pr[i][j] = pr[i - 1][pr[i - 1][j]];
            }
        }

        auto tmp = buildSufArray(s);
        sarr = tmp.first;
        sarr_inv.resize(sarr.size());
        for (int j = 0; j < (int)sarr.size(); j++) sarr_inv[sarr[j]] = j;
        mn = sparse(tmp.second);
    }

    int get_lcp(int i, int j) const {
        if (i == j) return (int)s.length() - i;

        i = sarr_inv[i];
        j = sarr_inv[j];
        if (i > j) swap(i, j);
        return mn.get(i, j - 1);
    }

    pair<int, int> calc_pos_max_pref(ll full_len, pair<int, int> pos_pref, pair<int, int> pos_suf) const {
        cnt1++;
        if (full_len > pos_pref.second - pos_pref.first) {
            return pos_pref;
        }
        cnt2++;

        int pref_len = pos_pref.second - pos_pref.first;
        int suf_len = pos_suf.second - pos_suf.first;

        auto check = [&](int suf) {
            int lcp = get_lcp(suf, pos_pref.first);
            bool less;
            if (lcp < pref_len) {
                char c1 = s[suf + lcp];
                char c2 = s[pos_pref.first + lcp];
                assert(c1 != c2);
                less = c1 < c2;
            } else {
                lcp = get_lcp(suf + pref_len, pos_suf.first);

                if (lcp >= suf_len) less = 0;
                else {
                    char c1 = s[suf + pref_len + lcp];
                    char c2 = s[pos_suf.first + lcp];
                    assert(c1 != c2);
                    less = c1 < c2;
                }
                lcp += pref_len;
                lcp = min(lcp, pref_len + suf_len);
            }
            return make_pair(lcp, less);
        };

        int L = 0, R = sarr.size();
        while (R - L > 1) {
            int M = (L + R) >> 1;

            bool less = check(sarr[M]).second;

            if (less) L = M;
            else R = M;
        }
        int csuf = 0, clen = 0;

        for (int i = R; i >= max(R - 1, 1); i--) {
            if (i < (int)s.length()) {
                int lcp = check(sarr[i]).first;
                if (clen < lcp) {
                    csuf = sarr[i];
                    clen = lcp;
                }
            }
        }

        return {csuf, csuf + clen};
    }

    int go_up(int cur_len, int need_len) const {
        if (cur_len <= need_len) return cur_len;
        for (int i = (int)pr.size() - 1; i >= 0; i--) {
            if (pr[i][cur_len] > need_len) {
                cur_len = pr[i][cur_len];
            }
        }
        assert(cur_len > need_len);
        cur_len = pr[0][cur_len];
        assert(cur_len <= need_len);
        return cur_len;
    }
};


int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        const int N = 2.01e6;
        char buf[N];
        scanf("%s", buf);
        string s = buf;

        int n = s.length();
        vector<int> nxt(n, n);
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == s[i + 1]) nxt[i] = nxt[i + 1];
            else nxt[i] = i + 1;
        }
        vector<int> prv(n, -1);
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) prv[i] = prv[i - 1];
            else prv[i] = i - 1;
        }

        vector<int> pos(n, -1);
        string ss = "";
        for (int i = 0; i < n; i++) {
            if (!ss.empty() && ss.back() == '1' && s[i] == '1') {
                ss.pop_back();
            } else {
                pos[i] = ss.length();
                ss += s[i];
            }
        }
        str_util u(ss);

        auto only_ones = [&](int l, int r) {
            return s[l] == '1' && nxt[l] > r;
        };

        struct res {
            int left_one;
            int right_one;
            int start;
            int len;
            res() {
                left_one = 0;
                right_one = 0;
                start = 0;
                len = 0;
            }
        };

        auto cmp = [&](res r1, res r2) {
            if (r1.left_one != r2.left_one) return false;
            if (r1.right_one != r2.right_one) return false;
            if (r1.len != r2.len) return false;
            return u.get_lcp(r1.start, r2.start) >= r1.len;
        };

        auto get = [&](int l, int r) {
            res rs = res();
            if (s[l] == '1') {
                int nl = nxt[l];
                if ((nl - l) % 2 != 0) rs.left_one = 1;
                l = nl;
            }
            if (s[r] == '1') {
                int nr = prv[r];
                if ((r - nr) % 2 != 0) rs.right_one = 1;
                r = nr;
            }
            assert(l <= r);
            assert(s[l] == '0' && s[r] == '0');
            assert(pos[l] != -1 && pos[r] != -1);
            rs.start = pos[l];
            rs.len = pos[r] - pos[l] + 1;
            return rs;
        };

        int q;
        scanf("%d", &q);
        for (int ii = 0; ii < q; ii++ ){
            int i1, i2, len;
            scanf("%d%d%d", &i1, &i2, &len);
            i1--; i2--;


            int l1 = i1, r1 = i1 + len - 1;
            int l2 = i2, r2 = i2 + len - 1;

            bool eq = 0;
            if (only_ones(l1, r1) || only_ones(l2, r2)) {
                eq = only_ones(l1, r1) == only_ones(l2, r2);
            } else {
                auto R1 = get(l1, r1);
                auto R2 = get(l2, r2);
                eq = cmp(R1, R2);
            }
            string s = eq ? "Yes" : "No";
            printf("%s\n", s.c_str());
        }
    }


    return 0;
}