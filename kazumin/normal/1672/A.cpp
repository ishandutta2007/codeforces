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
        int n, a[55], sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
        sum -= n - 1;
        if (sum & 1) printf("maomao90\n");
        else printf("errorgorn\n");
    }

    return 0;
}