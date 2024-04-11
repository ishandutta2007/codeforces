#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> first(n, n);
    vector<ll> csum(n + 1);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        first[a[i]] = min(first[a[i]], i);
        csum[i + 1] = csum[i] + a[i];
        mx = max(mx, a[i]);
    }

    int last = n;
    ll ans = 0;
    for (int cur = mx; cur >= 0; --cur) {
        if (first[cur] >= last) {
            first[cur] = last - 1;
        }
        ans += (ll(cur) * (last - first[cur])) - (csum[last] - csum[first[cur]]);

        last = first[cur];
    }

    cout << ans << endl;

    return 0;
}