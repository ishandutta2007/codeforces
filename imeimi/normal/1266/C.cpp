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
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        printf("0\n");
        return 0;
    }
    if (r == 1 || c == 1) {
        for (int i = 1; i < r + c; ++i) {
            printf("%d%c", i + 1, " \n"[c == 1]);
        }
        return 0;
    }
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            printf("%d ", i * (j + r));
        }
        printf("\n");
    }
    return 0;
}