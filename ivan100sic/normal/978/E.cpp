#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[1005], d;
ll z[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;

    ll mn = 0, mx = 0;

    for (int i=1; i<=n; i++) {
        cin >> a[i];
        z[i] = z[i-1] + a[i];
        mn = min(mn, z[i]);
        mx = max(mx, z[i]);
    }

    cout << max(0ll, d-(mx-mn-1)) << '\n';

}