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
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x != y && y != z && z != x) {
            printf("NO\n");
            continue;
        }
        if (y == z) swap(x, z);
        else if (x == z) swap(y, z);
        if (x < z) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        printf("%d %d %d\n", x, z, 1);
    }
    return 0;
}