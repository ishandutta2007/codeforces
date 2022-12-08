#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define int long long

typedef long long ll;

using namespace std;

void solve();
signed main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cout.precision(15); cout << fixed;
    solve();
    return 0;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> f;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        f[i - a[i]] = f[i - a[i]] + a[i];
        ans = max(ans, f[i - a[i]]);
    }
    cout << ans << endl;
}