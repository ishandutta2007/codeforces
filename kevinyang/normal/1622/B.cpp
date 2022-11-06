#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>p(n+1);
        for(int i = 1; i<=n; i++){
            cin >> p[i];
        }
        string s;
        cin >> s;
        vector<pair<int,int>>arr;
        vector<pair<int,int>>arr2;
        for(int i = 1; i<=n; i++){
            if(s[i-1]=='0'){
                arr.push_back({p[i],i});
            }
            else{
                arr2.push_back({p[i],i});
            }
        }
        sort(arr.begin(),arr.end());
        sort(arr2.begin(),arr2.end());
        vector<int>ans(n+1);
        int cur = 1;
        for(pair<int,int>nxt: arr){
            ans[nxt.second] = cur;
            cur++;
        }
        for(pair<int,int>nxt: arr2){
            ans[nxt.second] = cur;
            cur++;
        }
        for(int i = 1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}