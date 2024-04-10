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

int n, a[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int mx = 1, mn = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > a[mx]) mx = i;
            if (a[i] < a[mn]) mn = i;
        }
        printf("%lld %lld\n", mx, mn);
    }

    return 0;
}