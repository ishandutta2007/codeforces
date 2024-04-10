#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        
        map<string,pair<int,int>>hm;
        set<string>st;
        for(int i = 0; i<n; i++){
            string s2;
            cin >> s2;
            for(int j = 0; j<m; j++){
                if(j+2<=m){
                    st.insert(s2.substr(j,2));
                    hm[s2.substr(j,2)] = {i+1,j+1};
                }
                if(j+3<=m){
                    hm[s2.substr(j,3)] = {i+1,j+1};
                    st.insert(s2.substr(j,3));
                }
            }
        }
        string s;
        cin >> s;
        s = " " + s;
        vector<bool>dp(m+1);
        vector<pair<int,int>>prev(m+1);
        vector<int>len(m+1);
        dp[0] = true;
        for(int i = 2; i<=m; i++){
            if(i>2){
                if(st.find(s.substr(i-2,3))!=st.end()){
                    pair<int,int>p = hm[s.substr(i-2,3)];
                    if(dp[i-3]){
                        dp[i] = true;
                        prev[i] = p;
                        len[i] = 3;
                    }
                }
            }
            if(true){
                if(st.find(s.substr(i-1,2))!=st.end()){
                    pair<int,int>p = hm[s.substr(i-1,2)];
                    if(dp[i-2]){
                        dp[i] = true;
                        prev[i] = p;
                        len[i] = 2;
                    }
                }
            }
            //cout << dp[i];
        }
       // cout << "\n";
        if(dp[m]){
            int cur = m;
            vector<pair<pair<int,int>,int>>arr;
            while(cur>0){
                pair<int,int>p = prev[cur];
                arr.push_back({{p.second,p.second+len[cur]-1},p.first});
                cur-=len[cur];
            }
            reverse(arr.begin(),arr.end());
            cout << arr.size() << "\n";
            for(auto nxt: arr){
                cout << nxt.first.first << " " << nxt.first.second << " " << nxt.second << "\n";
            }
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}