#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    int arr[n + 5];
    int sum = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "YES\n";
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> gd;
    for(int i = 1; i <= m; i++) gd.push(mp(0, i));
    for(int i = 0; i < n; i++) {
        pair<int, int> now = gd.top();
        cout << now.se << ' ';
        gd.pop();
        gd.push(mp(now.fi + arr[i], now.se));
    }
    cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    cin >> t;
    
    while(t--) solve();
    return 0;
}