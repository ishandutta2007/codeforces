#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;

const string YES = "YES";
const string NO = "NO";

const int MOD = 998244353;

void print(vector<ll> a) {
    for (ll x : a) printf("%lld\n", x);
}

const int K = 13;
const int N = 1 << K;

ll cnt[N];


const int SZ = 1e6; // >3^12 + 3^11 + ..
int sz;

int nxt[SZ][3];
vector<pair<int, int>> vct[SZ];

void init() {
    sz = 1;
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < SZ; i++) vct[i].clear();
}

int getId(char c) {
    if (c == 'A') return 0;
    if (c == 'O') return 1;
    if (c == 'X') return 2;
    assert(0);
}

void add(string s, int id) {
    int need = 0;
    int cur = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            need ^= 1 << i;
            c = c - 'a' + 'A';
        }
        int cc = getId(c);
        if (nxt[cur][cc] == -1) {
            nxt[cur][cc] = sz++;
        }
        cur = nxt[cur][cc];
    }
    vct[cur].push_back({id, need});
}

vector<ll> ans;

int w;

void oft(int bit, int rev) {
    int n = 1 << w;
    int k = 1 << bit;
    for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
            if (!rev) {
                cnt[i + k + j] += cnt[i + j];
            } else {
                cnt[i + k + j] -= cnt[i + j];
            }
        }
    }
}

void aft(int bit, int rev) {
    int n = 1 << w;
    int k = 1 << bit;
    for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
            if (!rev) {
                cnt[i + j] += cnt[i + k + j];
            } else {
                cnt[i + j] -= cnt[i + k + j];
            }
        }
    }
}

void xft(int bit, int rev) {
    int n = 1 << w;
    int k = 1 << bit;
    for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
            ll u = cnt[i + j];
            ll v = cnt[i + k + j];
            cnt[i + j] = u + v;
            cnt[i + k + j] = u - v;
        }
    }
    if (rev) {
        for (int i = 0; i < n; i++) {
            cnt[i] /= 2;
        }
    }
}

void rec(int x, int v, vector<int> mask) {
    if (x == w) {
        for (auto o : vct[v]) {
            int id = o.first;
            int need = o.second;

            ll res = 0;
            int m1, m2, dif;
            int all = (1 << w) - 1;
            for (int i = 0; i < (1 << w); i++) {
                int sign = 1;

                m1 = need & mask[0];
                m2 = i    & mask[0];
                if (!((m1 & m2) == m1)) continue;
                dif = m1 ^ m2;
                if (__builtin_popcount(dif) % 2) sign *= -1;


                m1 = need & mask[1];
                m2 = i    & mask[1];
                if (!((m1 & m2) == m2)) continue;
                dif = m1 ^ m2;
                if (__builtin_popcount(dif) % 2) sign *= -1;

                m1 = need & mask[2];
                m2 = i    & mask[2];
                ///dif = m2 & (m1 ^ m2);
                dif = m1 & m2;
                if (__builtin_popcount(dif) % 2) sign *= -1;

                res += sign * cnt[i] * cnt[i];
            }
            /*vector<ll> old(1 << w);
            for (int i = 0; i < (1 << w); i++) old[i] = cnt[i];
            for (int i = 0; i < (1 << w); i++) cnt[i] = 1LL * cnt[i] * cnt[i];
            for (int i = 0; i < w; i++) {
                if (mask[0] & (1 << i)) {
                    aft(i, 1);
                }
                if (mask[1] & (1 << i)) {
                    oft(i, 1);
                }
                if (mask[2] & (1 << i)) {
                    xft(i, 1);
                }
            }
            res = cnt[need];
            for (int i = 0; i < (1 << w); i++) cnt[i] = old[i];*/

            res /= 1LL << ((int)__builtin_popcount(mask[2]));
            ans[id] = res;
        }
        return;
    }
    for (int c = 0; c < 3; c++) {
        if (nxt[v][c] == -1) continue;
        if (c == 0) {
            aft(x, 0);
        } else if (c == 1) {
            oft(x, 0);
        } else {
            xft(x, 0);
        }

        auto nmask = mask;
        nmask[c] |= 1 << x;
        rec(x + 1, nxt[v][c], nmask);

        if (c == 0) {
            aft(x, 1);
        } else if (c == 1) {
            oft(x, 1);
        } else {
            xft(x, 1);
        }
    }
}

vector<ll> fast(int _w, vector<int> a, vector<string> b) {
    for (auto &s : b) {
        reverse(s.begin(), s.end());
    }
    w = _w;
    memset(cnt, 0, sizeof(cnt));
    for (int x : a) cnt[x]++;

    init();
    for (int i = 0; i < (int)b.size(); i++) {
        add(b[i], i);
    }
    ans.assign(b.size(), -1);
    rec(0, 0, vector<int>(3, 0));


    return ans;
}

void test() {
    int cw = 12;
    int n = 3e4;
    int m = 5e4;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = rand() % (1 << w);
    vector<string> b(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < cw; j++) {
            b[i] += "AOXaox"[rand() % 6];
        }
    }
    fast(cw, a, b);
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    exit(0);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    //test();

    bool first = 1;
    int cw, n, m;
    while (scanf("%d%d%d", &cw, &n, &m) == 3) {
        if (first) first = 0;
        else printf("\n");

        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        vector<string> b(m);
        for (int i = 0; i < m; i++) {
            static char buf[(int)1e5];
            scanf("%s", buf);
            b[i] = buf;
        }

        print(fast(cw, a, b));
        //return 0;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}