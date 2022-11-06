#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,p;
    cin >> n >> p;
    vector<int>arr(n+1);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int>dp(p+69);
    map<int,int>hm;
    for(int i = 1; i<=n; i++){
        int k = arr[i];
        bool f = false;
        while(k!=0){
            if(hm[k]){
                f = true;
                break;
            }
            if(k%2==1){
                k--;
                k/=2;
                continue;
            }
            if(k%4==0){
                k/=4;
                continue;
            }
            break;
        }
        hm[arr[i]] = 1;
        if(!f){
            for(int j = 0; j<31; j++){
                if((1<<j)>arr[i]){
                    dp[j]++;
                    break;
                }
            }
        }
    }
    for(int i = 2; i<=p; i++){
        dp[i]+=dp[i-1]+dp[i-2];
        dp[i]%=mod;
    }
    int ans = 0;
    for(int i = 1; i<=p; i++){
        ans+=dp[i];ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}