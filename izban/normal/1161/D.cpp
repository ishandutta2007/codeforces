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


const int INF = 1.01e9;

namespace mod {
    typedef long long ll;
    const int MOD = 998244353;

    void add(int &a, ll b) {
        a = (a + b) % MOD;
    }

    int mul(int a, int b) {
        return 1LL * a * b % MOD;
    }

    int bin(int a, ll n) {
        int res = 1;
        while (n) {
            if (n & 1) res = 1LL * res * a % MOD;
            a = 1LL * a * a % MOD;
            n >>= 1;
        }
        return res;
    }

    int inv(int x) {
        return bin(x, MOD - 2);
    }

    vector<int> fct, ofct, rev;

    void ensureFact(int n) {
        if ((int)fct.size() > n) return;
        int old = fct.size();
        fct.resize(n + 1);
        ofct.resize(n + 1);
        rev.resize(n + 1);
        if (old == 0) {
            fct[0] = ofct[0] = 1;
            rev[0] = 0;
            old++;
        }
        for (int i = old; i <= n; i++) {
            fct[i] = mul(fct[i - 1], i);
            if (i == 1) rev[i] = 1;
            else rev[i] = (MOD - mul(MOD / i, rev[MOD % i])) % MOD;
            ofct[i] = mul(ofct[i - 1], rev[i]);
        }
    }

    int getC(int n, int k) {
        if (n < k || k < 0) return 0;
        ensureFact(n);
        return mul(fct[n], mul(ofct[k], ofct[n - k]));
    }
}
using namespace mod;

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    string s;
    while  (cin >> s) {
        int n = s.length();

        int res = 0;
        for (int i = 1; i < n; i++) {
            int sz = n * 2 + 2;
            vector<vector<pair<int, int>>> e(sz);

            vector<int> c(sz, -1);
            c[n * 2] = 0;
            c[n * 2 + 1] = 1;

            auto addEdge = [&](int u, int v, int z) {
//                db3(u, v, z);
                e[u].push_back({v, z});
                e[v].push_back({u, z});
            };

            for (int j = 0; j < n - 1 - j; j++) {
                addEdge(j, n - 1 - j, 0);
            }
            for (int j = i; j < n - 1 - (j - i); j++) {
                addEdge(n + j, n + n - 1 - (j - i), 0);
            }
            for (int j = 0; j < i; j++) {
                addEdge(n + j, n * 2, 0);
            }
            addEdge(0, n * 2 + 1, 0);
            addEdge(n + i, n * 2 + 1, 0);
            for (int j = 0; j < n; j++) {
                if (s[j] != '?') {
                    addEdge(j, n + j, s[j] - '0');
                }
            }


            function<bool(int, int)> dfs = [&](int v, int col) {
                if (c[v] != -1) {
                    return c[v] == col;
                }
                c[v] = col;
                for (auto o : e[v]) {
                    if (!dfs(o.first, col ^ o.second)) {
                        return false;
                    }
                }
                return true;
            };
            bool ans = 1;
            int ways = 1;
            for (int i = sz - 1; ans && i >= 0; i--) {
                if (i < n * 2 && c[i] != -1) continue;
                int cur = c[i];
                if (cur == -1) {
                    ways = 2LL * ways % MOD;
                    cur = 0;
                } else c[i] = -1;
                ans &= dfs(i, cur);
            }
            if (ans) {
                res = (res + ways) % MOD;
            }
        }
        cout << res << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}