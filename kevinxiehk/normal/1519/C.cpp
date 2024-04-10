#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
#define int long long
using namespace std;
void solve() {
    int n, t;
    cin >> n;
    vector<int> arr[n + 5];
    int uni[n + 5];
    pair<int, int> cnt[n + 5];
    for(int i = 0; i <= n; i++) cnt[i] = mp(0, i);
    for(int i = 0; i < n; i++) cin >> uni[i];
    for(int i = 0; i < n; i++) {
        cin >> t;
        arr[uni[i]].pb(t);
        cnt[uni[i]].fi++;
    }
    sort(cnt, cnt + n + 1);
    reverse(cnt, cnt + n + 1);
    for(int i = 1; i <= n; i++) {
        sort(arr[i].begin(), arr[i].end());
        reverse(arr[i].begin(), arr[i].end());
        for(int j = 1; j < arr[i].size(); j++) {
            arr[i][j] += arr[i][j - 1];
            //cout << i << ' ' << j << ' ' << arr[i][j] << '\n';
        }
    }
    for(int i = 1; i <= n; i++) {
        int ans = 0;
        for(int j = 0; j < n; j++) {
            if(cnt[j].fi < i) break;
            int t = cnt[j].fi / i * i;
            //cout << cnt[j].se << ' ' << t << '\n';
            ans += arr[cnt[j].se][t - 1];
        }
        cout << ans << ' ';
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