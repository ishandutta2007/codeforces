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
        int n, a, b;
        cin >> n >> a >> b;
        if (a + b > n - 2 || abs(a - b) > 1) {
            printf("-1\n");
            continue;
        }
        if (a == b + 1) {
            int x = 1, y = n;
            for (int i = 1; i <= n - 2 - a - b; ++i) printf("%d ", x++);
            for (int i = 1; x <= y; ++i) {
                if (i & 1) printf("%d ", x++);
                else printf("%d ", y--);
            }
        }
        else {
            int x = n, y = 1;
            for (int i = 1; i <= n - 2 - a - b; ++i) printf("%d ", x--);
            for (int i = 1; x >= y; ++i) {
                if (i & 1) printf("%d ", x--);
                else printf("%d ", y++);
            }            
        }
        printf("\n");
    }
    return 0;
}