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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int n;
    cin >> n;
    int add = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x & 1) {
            if (add) {
                printf("%d\n", x >> 1);
            }
            else {
                printf("%d\n", x + 1 >> 1);
            }
            add ^= 1;
        }
        else {
            printf("%d\n", x >> 1);
        }
    }
    return 0;
}