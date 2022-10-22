#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, a[MN];

int gcd(int x, int y) {
    if (!x) return y;
    if (!y) return x;
    return __gcd(x, y);
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int on = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 1) on++;
        }
        sort(a + 1, a + n + 1);
        if (!on) printf("YES\n");
        else {
            int cnt = 0;
            for (int i = 1; i < n; i++) if (a[i + 1] - a[i] == 1) cnt++;
            if (!cnt) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}