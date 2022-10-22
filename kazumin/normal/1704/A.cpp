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
        int n, a[105], m, b[105];
        char c;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> c;
            a[i] = c - '0';
        }
        for (int i = 1; i <= m; i++) {
            cin >> c;
            b[i] = c - '0';
        }
        int p1 = n, p2 = m;
        while (p1 && p2 && a[p1] == b[p2]) p1--, p2--;
        if (!p2) printf("YES\n");
        else if (p2 != 1) printf("NO\n");
        else {
            bool ok = 0;
            for (int i = 1; i <= p1; i++) ok |= a[i] == b[p2];
            if (ok) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}