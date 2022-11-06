#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isgood(int x){
    string s = to_string(x);
    string s2 = s;
    reverse(s2.begin(),s2.end());
    if(s2==s)return true;
    return false;
}
const int mod = (int)1e9+7;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int>arr;
    for(int i = 1; i<=40000; i++){
        if(isgood(i)){
            arr.push_back(i);
        }
    }

    vector<int>dp(40005);
    dp[0] = 1;
    for(int nxt: arr){
        for(int i = nxt; i<=40000; i++){
            dp[i]+=dp[i-nxt];
            dp[i]%=mod;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}