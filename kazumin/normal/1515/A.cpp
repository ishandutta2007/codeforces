#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n, x, a[105];
        cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int sum = 0;
        bool bad = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i];
            if (sum == x) {
                if (i == n) bad = 1;
                else swap(a[i], a[i + 1]);
            }
        }
        if (bad) printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
            printf("\n");
        }
    }

    return 0;
}