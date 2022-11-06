#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (n >= k + k - 1) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == j && (i & 1) == 0 && i < k + k) printf("R");
                    else printf(".");
                }
                printf("\n");
            }
        }
        else printf("-1\n");
    }
    return 0;
}