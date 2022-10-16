#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
int arr[2005];
void shift(int k, int a) {
    int arr2[k + 5];
    for(int i = 0; i < k; i++) arr2[i] = arr[(i + a) % k];
    for(int i = 0; i < k; i++) arr[i] = arr2[i];
}
void solve(int TC) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> ans;
    for(int i = n; i >= 1; i--) {
        int id = -1;
        for(int j = 0; j < i; j++) if(arr[j] == i) id = j;
        ans.pb((id + 1) % i);
        shift(i, (id + 1) % i);
    }
    reverse(ans.begin(), ans.end());
    for(auto x: ans) cout << x << ' '; cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}