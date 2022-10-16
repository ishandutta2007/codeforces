#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
vector<int> uh;
bool hm() {
    int sum = 0;
    for(auto x: uh) sum += x;
    if(sum % 2 == 1) return false;
    int aim = sum / 2;
    int dp[aim + 5];
    memset(dp, 0, sizeof dp);
    for(auto x: uh) {
        for(int i = aim; i >= x; i--) dp[i] = max(dp[i], dp[i - x] + x);
    }
    //for(int i = 0; i <= aim; i++) cout << i << ' ' << dp[i] << '\n';
    return dp[aim] == aim;
}
void solve() {
    int n;
    cin >> n;
    int arr[n + 5];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        uh.pb(arr[i]);
    }
    if(!hm()) {
        cout << "0\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        int t = uh[0];
        uh.erase(uh.begin());
        if(!hm()) {
            cout << "1\n" << i + 1 << '\n';
            return;
        }
        uh.pb(t);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    //cin >> t;
    
    while(t--) solve();
    return 0;
}