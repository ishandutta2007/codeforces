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
    const int MOD = (int)1e9 + 7;

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

int getC2(int n, int k) {
    return getC(n + k - 1, k - 1);
}

int solve(int n, int m, int a, int b) {
    /*vector<int> ans(n);
    vector<int> pr(n);
    function<void(int)> rec = [&](int x) {
        if (x == n) {
            for (int i = 0; i < n; i++) {
                int cur = i;
                for (int j = 0; j < n; j++) cur = pr[cur];
                if (cur != 0) return;
            }
            int len = 0;
            int cur = 1;
            while (cur != 0) {
                cur = pr[cur];
                len++;
            }
            ans[len]++;
            return;
        }
        for (int i = 0; i < n; i++) {
            pr[x] = i;
            rec(x + 1);
        }
    };
    rec(1);*/
    int res = 0;
    for (int len = 1; len < n; len++) {
        //int cur = ans[len];
        int s = n - len;
        int cur = bin(n, max(0, s - 2));
        if (s == 1) cur = 1LL * cur * inv(n) % MOD;
        cur = 1LL * cur * (len + 1) % MOD;
        if (len > 1) cur = 1LL * cur * getC(n - 2, len - 1) % MOD * fct[len - 1] % MOD;
        //cur = 1LL * cur * getC(n - 2, len - 1) % MOD;

        //cur = 1LL * cur * (len + 1) % MOD;
        cur = 1LL * cur * bin(m, n - 1 - len) % MOD;
        cur = 1LL * cur * getC2(m - len, len) % MOD;
        res = (res + cur) % MOD;
    }
    return res;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    /* for (int n = 2; n <= 10; n++) {
         vector<int> dp(n + 1);
         dp[0] = 1;
         for (int i = 1; i <= n; i++) {
             int k = i;
             dp[i] = getC(n - 2, i - 1) * 1LL * (k == 1 ? 1 : bin(k, k - 2)) % MOD;
         }
         for (int i = 0; i ,)
     }*/

    if (0) {
        for (int n = 2; n <= 9; n++) {
            vector<int> ans(n);
            vector<int> pr(n);
            function<void(int)> rec = [&](int x) {
                if (x == n) {
                    for (int i = 0; i < n; i++) {
                        int cur = i;
                        for (int j = 0; j < n; j++) cur = pr[cur];
                        if (cur != 0) return;
                    }
                    int len = 0;
                    int cur = 1;
                    while (cur != 0) {
                        cur = pr[cur];
                        len++;
                    }
                    ans[len]++;
                    return;
                }
                for (int i = 0; i < n; i++) {
                    pr[x] = i;
                    rec(x + 1);
                }
            };
            rec(1);

            int sum = 0;
            cout << n << ": ";
            for (int i = (int)ans.size() - 1; i > 0; i--) {
                int x = ans[i];
                sum += x;
                cout << x << " ";
            }
            cout << endl;
        }
        return 0;
    }

    if (0) {
        for (int n = 2; n <= 6; n++) {
            for (int m = 1; m <= 6; m++) {
                cout << solve(n, m, 1, 2) << " ";
            }
            cout << endl;
        }
        return 0;
    }

    int n, m, a, b;
    while (cin >> n >> m >> a >> b) {
        cout << solve(n, m, a, b) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}