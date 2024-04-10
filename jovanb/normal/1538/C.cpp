#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a[200005];

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    int j = n, k = n+1;
    ll res = 0;
    for(int i=1; i<=n; i++){
        while(j > 0 && a[j] + a[i] > r) j--;
        while(k > 1 && a[k-1] + a[i] >= l) k--;
        res += max(0, min(i-1, j)-k+1);
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}