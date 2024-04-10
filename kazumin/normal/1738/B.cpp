#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int t, n, k, a[MN], s[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= k; i++) cin >> s[n - k + i];
        if (k == 1) {printf("YES\n"); continue;}
        for (int i = n; i > n - k + 1; i--) a[i] = s[i] - s[i - 1];
        int rem = s[n - k + 1];
        int cnt = n - k + 1;
        for (int i = n - k + 1; i > 0; i--) a[i] = a[i + 1], rem -= a[i];
        if (rem > 0) {printf("NO\n"); continue;}
        bool ok = 1;
        for (int i = 1; i < n; i++) ok &= a[i] <= a[i + 1];
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}