#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(k==n-1){
            if(n==4){
                cout << "-1\n";
                continue;
            }
            vector<pair<int,int>>ans;
            ans.push_back({n-2,n-1});
            ans.push_back({1,3});
            ans.push_back({0,n-4});
            for(int i = 0; i<n/2; i++){
                if(i==0||i==1||i==3)continue;
                ans.push_back({i,n-1-i});
            }
            for(pair<int,int>nxt: ans){
                cout << nxt.first << " " << nxt.second << "\n";
            }
            continue;
        }
        vector<int>ans(n);
        int idx = 0;
        for(int i = 0; i<n/2; i++){
            ans[i] = (n-1)^i;
            if(i==k)idx = i;
            if(((n-1)^i)==k)idx = i;
        }
        for(int i = 0; i<n/2; i++){
            if(i==0){
                cout << i << " " << ((n-1)^k) << "\n";
            }
            else if(i==idx){
                cout << k << " " << n-1 << "\n";
            }
            else{
                cout << ans[i] << " " << i << "\n";
            }
        }
    }
    return 0;
}