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
        vector<int>arr;
        vector<int>arr2;
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            if(x<0){
                arr.push_back(x*-1);
            }
            if(x>0){
                arr2.push_back(x);
            }
        }
        sort(arr.begin(),arr.end());
        sort(arr2.begin(),arr2.end());
        vector<int>vals;
        int ans = 0;
        if(arr.size()){
            for(int i = arr.size()-1; i>=0; i-=k){
                vals.push_back(arr[i]);
            }
        }
        if(arr2.size()){
            for(int i = arr2.size()-1; i>=0; i-=k){
                vals.push_back(arr2[i]);
            }
        }
        sort(vals.begin(),vals.end());
        for(int i = 0; i<vals.size(); i++){
            ans+=vals[i]*2;
        }
        if(vals.size()){
            ans-=vals[vals.size()-1];
        }
        cout << ans << "\n";
    }
    return 0;
}