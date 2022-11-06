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
        if (a > b + 1) {
            printf("-1\n");
            continue;
        }
        if (a == b + 1 && b != n / 2) {
            printf("-1\n");
            continue;
        }
        if (a < b && (a > n / 2 || b <= n / 2)) {
            printf("-1\n");
            continue;
        }
        vector<bool> used(n + 1, false);
        used[a] = used[b] = 1;
        printf("%d ", a);
        for (int i = n, c = n / 2 - 1; c > 0; --i) {
            if (used[i]) continue;
            printf("%d ", i);
            used[i] = true;
            --c;
        }
        for (int i = 1, c = n / 2 - 1; c > 0; ++i) {
            if (used[i]) continue;
            printf("%d ", i);
            used[i] = true;
            --c;
        }
        printf("%d\n", b);
    }
    return 0;
}