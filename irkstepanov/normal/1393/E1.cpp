#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct SuffixArray {

    SuffixArray() {}

    SuffixArray(const vector<int>& s) : s(s) {
        p.resize(nmax);
        c.resize(nmax);
        cnt.assign(nmax, 0);
        pn.resize(nmax);
        cn.resize(nmax);
        lcp.resize(nmax);
        pos.resize(nmax);
        deg.resize(nmax);
        sparse = vector<vector<int> >(rmax, vector<int>(nmax));
        n = sz(s);
        for (int i = 0; i < sz(s); ++i) {
            ++cnt[s[i]];
        }
        for (int i = 1; i < sigma; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            p[--cnt[s[i]]] = i;
        }
        c[p[0]] = 0;
        int curr = 0;
        for (int i = 1; i < n; ++i) {
            if (s[p[i]] != s[p[i - 1]]) {
                ++curr;
            }
            c[p[i]] = curr;
        }
        ++curr;
        int len = 2;
        while (true) {
            for (int i = 0; i < n; ++i) {
                pn[i] = p[i] - (len >> 1);
                if (pn[i] < 0) {
                    pn[i] += n;
                }
            }
            cnt.assign(curr, 0);
            for (int i = 0; i < n; ++i) {
                ++cnt[c[i]];
            }
            for (int i = 1; i < curr; ++i) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; --i) {
                p[--cnt[c[pn[i]]]] = pn[i];
            }
            cn[p[0]] = 0;
            curr = 0;
            for (int i = 1; i < n; ++i) {
                if (c[p[i]] != c[p[i - 1]]) {
                    ++curr;
                } else {
                    int x = p[i] + (len >> 1), y = p[i - 1] + (len >> 1);
                    if (x >= n) {
                        x -= n;
                    }
                    if (y >= n) {
                        y -= n;
                    }
                    if (c[x] != c[y]) {
                        ++curr;
                    }
                }
                cn[p[i]] = curr;
            }
            ++curr;
            c = cn;
            if (len >= n) {
                break;
            }
            len <<= 1;
        }

        deg[1] = 0;
        for (int i = 2; i < nmax; ++i) {
            deg[i] = deg[i - 1];
            if (!(i & (i - 1))) {
                ++deg[i];
            }
        }

        for (int i = 0; i < n; ++i) {
            pos[p[i]] = i;
        }

        curr = 0;
        for (int i = 0; i < n; ++i) {
            curr = max(curr - 1, 0);
            if (pos[i] + 1 == n) {
                curr = 0;
                continue;
            }
            int j = p[pos[i] + 1];
            while (i + curr < n && j + curr < n && s[i + curr] == s[j + curr]) {
                ++curr;
            }
            lcp[pos[i]] = curr;
        }

        for (int i = 0; i < n; ++i) {
            sparse[0][i] = lcp[i];
        }
        for (int r = 0; r + 1 < rmax; ++r) {
            for (int i = 0; i < n; ++i) {
                int j = min(n - 1, i + (1 << r));
                sparse[r + 1][i] = min(sparse[r][i], sparse[r][j]);
            }
        }
    }

    int get(int l, int r) const {
        int len = r - l + 1;
        int k = deg[len];
        return min(sparse[k][l], sparse[k][l + len - (1 << k)]);
    }

    int LCP(int i, int j) {
        int l = pos[i], r = pos[j];
        if (l == r) {
            return nmax;
        }
        if (l > r) {
            swap(l, r);
        }
        return get(l, r - 1);
    }

    vector<int> s;
    int n;

    static const int nmax = 1e6 + 2;
    static const int rmax = 21;
    static const int sigma = 1e6 + 2;
    
    vector<int> p, c, cnt, pn, cn, lcp, pos, deg;
    vector<vector<int> > sparse;
};

int n;
vector<string> s;
vector<int> pref;
SuffixArray sa;
vector<int> t;

int sgn(int a, int b) {
    if (a < b) {
        return -1;
    } else if (a == b) {
        return 0;
    } else {
        return 1;
    }
}

int sgn(int l1, int r1, int x1, int l2, int r2, int x2) {
    //cout << "!" << l1 << " " << r1 << " " << x1 << " " << l2 << " " << r2 << " " << x2 << endl;
    if (x1 > x2) {
        return -sgn(l2, r2, x2, l1, r1, x1);
    }
    int a = sa.LCP(l1, l2);
    if (a < x1) {
        return sgn(t[l1 + a], t[l2 + a]);
    }
    if (x1 == r1 - l1 + 1) {
        int tmp = r2 - l2 + 1;
        if (x2 != tmp) {
            --tmp;
        }
        if (r1 - l1 + 1 != tmp) {
            return -1;
        } else {
            return 0;
        }
    }
    return sgn(l1 + x1 + 1, r1, r1 - (l1 + x1 + 1) + 1, l2 + x1, r2, x2 - x1);
}

int sgn(int i, int x, int j, int y) {
    return sgn(pref[i], pref[i] + sz(s[i]) - 1, x, pref[j], pref[j] + sz(s[j]) - 1, y);
}

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int sgn(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < sz(a); ++i) {
        if (i >= sz(b)) {
            return 1;
        }
        if (a[i] != b[i]) {
            if (a[i] < b[i]) {
                return -1;
            } else {
                return 1;
            }
        }
    }
    if (sz(a) == sz(b)) {
        return 0;
    } else {
        return -1;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    

    cin >> n;
    s.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    pref.pb(0);
    for (int i = 0; i < n - 1; ++i) {
        int x = pref.back();
        pref.pb(x + sz(s[i]));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(s[i]); ++j) {
            t.pb(s[i][j]);
        }
    }
    t.pb(0);
    sa = SuffixArray(t);

    vector<vector<int> > dp(2);
    int ptr = 0;
    vector<int> prev;
    for (int x = 0; x <= sz(s[0]); ++x) {
        prev.pb(x);
        dp[0].pb(1);
    }
    sort(all(prev), [&] (int x, int y) { return sgn(0, x, 0, y) == -1; });

    for (int i = 1; i < n; ++i) {
        vector<int> nx;
        for (int x = 0; x <= sz(s[i]); ++x) {
            nx.pb(x);
        }
        sort(all(nx), [&] (int x, int y) { return sgn(i, x, i, y) == -1; });
        vector<int> sums;
        sums.pb(dp[ptr][0]);
        for (int x = 1; x < sz(dp[ptr]); ++x) {
            int val = sums.back();
            add(val, dp[ptr][x]);
            sums.pb(val);
        }
        int p = -1;
        for (int x : nx) {
            while (p + 1 < sz(prev) && sgn(i - 1, prev[p + 1], i, x) <= 0) {
                ++p;
            }
            int val = 0;
            if (p != -1) {
                val = sums[p];
            }
            dp[ptr ^ 1].pb(val);
        }
        prev.swap(nx);
        dp[ptr].clear();
        ptr ^= 1;
    }

    int ans = 0;
    for (int x : dp[ptr]) {
        add(ans, x);
    }
    cout << ans << "\n";

}