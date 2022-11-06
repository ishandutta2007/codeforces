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

int n, A[2005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int x = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
            x ^= A[i];
        }
        if (x == 0) {
            printf("YES\n");
            continue;
        }
        int r = x, cnt = 0;
        x = 0;
        for (int i = 1; i <= n; ++i) {
            x ^= A[i];
            if (x == r) x = 0, ++cnt;
        }
        if (cnt > 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}