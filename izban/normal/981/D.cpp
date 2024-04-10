#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        vector<ll> a(n);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);


        ll cans = 0;
        for (int j = 60; j >= 0; j--) {
            cans |= 1LL << j;

            
            vector<vector<char>> can(n + 1, vector<char>(k + 1));
            can[0][0] = 1;
            for (int l = 0; l < n; l++) {
                for (int t = 0; t < k; t++) {
                    if (!can[l][t]) continue;
                    ll sum = 0;
                    for (int r = l; r < n; r++) {
                        sum += a[r];
                        if ((sum & cans) == cans) {
                            can[r + 1][t + 1] = 1;
                        }
                    }
                }
            }
            if (!can[n][k]) {
                cans ^= 1LL << j;
            }
        }
        cout << cans << endl;
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}