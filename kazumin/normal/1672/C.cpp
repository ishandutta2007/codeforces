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

int32_t main() {
    boost();

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<int> v;
        for (int i = 1; i < n; i++) if (a[i] == a[i + 1]) v.push_back(i);
        if (v.size() <= 1) printf("0\n");
        else {
            int p = v[0], q = v.back();
            int ans = max(1ll, q - p - 1);
            printf("%lld\n", ans);
        }
    }

    return 0;
}