// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
int a[4005];

void mx(ll& x, ll y) {
    x = max(x, y);
}

vector<ll> solve(int l, int r) {
    if (r-l == 0) {
        return {0ll}; 
    }

    int mid = min_element(a+l, a+r) - a;

    auto lv = solve(l, mid);
    auto rv = solve(mid+1, r);

    vector<ll> z(r-l+1, 0);

    for (int i=0; i<=mid-l; i++) {
        for (int j=0; j<=r-mid-1; j++) {
            mx(z[i+j], lv[i] + rv[j] - 2ll*i*j*a[mid]);
            mx(z[i+j+1], lv[i] + rv[j] + 1ll*m*a[mid] - (2ll*(i+1)*(j+1)-1)*a[mid]);
        }
    }

    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    cout << solve(0, n)[m] << '\n';
}