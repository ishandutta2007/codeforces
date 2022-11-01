#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll n, k;
bool ok(ll a[], ll m) {
    ll count = 0;
    for (ll i = n / 2; i < n; i++) {
        if (a[i] >= m) break;
        count += m - a[i];
    }  
    return count <= k;
}
void solve() {
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll l = 0;
    ll h = 1e12;
    while (l <= h) {
        ll m = l + (h - l) / 2;
        if (ok(a, m)) l = m + 1;
        else h = m - 1;
    }
    cout << h << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    // cin>>q;
    q = 1;
    while(q--) {
        solve();
    }
    return 0;
}