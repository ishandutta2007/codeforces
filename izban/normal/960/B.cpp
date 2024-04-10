#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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

    int n, k1, k2;
    while (cin >> n >> k1 >> k2) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int k = k1 + k2;
        vector<int> c(n);
        for (int i = 0; i < n; i++) c[i] = abs(a[i] - b[i]);

        for (int i = 0; i < k; i++) {
            int j = max_element(c.begin(), c.end()) - c.begin();
            if (c[j] > 0) {
                c[j]--;
            } else {
                c[j]++;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) ans += 1LL * c[i] * c[i];
        cout << ans << endl;
    }


#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}