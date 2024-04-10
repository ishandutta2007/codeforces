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

int n, m, k, a[MN];

bool check(int n, int m) {
    int tot = 0, ex = 0;
    for (int i = 1; i <= k; i++) {
        int w = a[i] / m;
        if (w < 2) continue;
        tot += w;
        if (w > 2) ex = 1;
    }
    if (n % 2 == tot % 2) return tot >= n;
    else return ex && tot >= n;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= k; i++) cin >> a[i];
        bool ok = check(n, m) || check(m, n);
        if (ok) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}