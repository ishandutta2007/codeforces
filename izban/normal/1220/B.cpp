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

vector<ll> factor(ll x) {
    vector<ll> res;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i * i != x) {
                res.push_back(x / i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<vector<ll>> a(n, vector<ll>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld", &a[i][j]);
            }
        }

        mt19937 rnd(time(0));
        int row = rnd() % n;

        ll g = 0;
        for (int j = 0; j < n; j++) {
            g = __gcd(a[row][j], g);
        }

        auto divs = factor(g);
        shuffle(divs.begin(), divs.end(), rnd);

        vector<ll> ans;
        for (ll x : divs) {
            vector<ll> b(n);
            b[row] = x;

            bool ok = 1;
            for (int i = 0; i < n; i++) {
                if (i == row) continue;
                if (a[i][row] % x != 0) {
                    ok = 0;
                    break;
                }
                b[i] = a[i][row] / x;
            }
            for (int i = 0; i < n; i++) {
                if (!ok) break;
                for (int j = i + 1; j < n; j++) {
                    ll prod = b[i] * b[j];
                    if (prod != a[i][j]) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) {
                ans = b;
                break;
            }
        }
        assert(ans.size() == n);
        for (int i = 0; i < n; i++) printf("%lld%c", ans[i], " \n"[i + 1 == n]);
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}