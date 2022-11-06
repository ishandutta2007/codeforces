#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int,pair<int,int>> solve(vector<pair<int,int>>arr){
    int cur = 0;
    int ans = 0;
    pair<int,int>p = {1,1};
    int l = 0;
    for(pair<int,int> nxt: arr){
        if(cur==0){
            l = nxt.first;
            cur = nxt.second;
        }
        else{
            cur+=nxt.second;
        }
        if(cur<0)cur = 0;

        if(cur>ans){
            ans = cur;
            p = {l,nxt.first};
        }
    }
    pair<int,pair<int,int>>ret = {ans,p};
    return ret;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n+1);
        vector<int>sorted;
        sorted.push_back(0);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
            sorted.push_back(arr[i]);
        }
        sort(sorted.begin(),sorted.end());
        for(int i = 1; i<=n; i++){
            arr[i] = lower_bound(sorted.begin(),sorted.end(),arr[i])-sorted.begin();
        }
        vector<vector<int>>idx(n+1);
        for(int i = 1; i<=n; i++){
            idx[arr[i]].push_back(i);
        }
        int mx = 0;
        pair<int,int>p = {1,1};
        int ans = arr[1];
        for(int i = 1; i<=n; i++){
            if(idx[i].size()){
                vector<pair<int,int>>a;
                a.push_back({idx[i][0],1});
                for(int j = 1; j<idx[i].size(); j++){
                    a.push_back({idx[i][j],-(idx[i][j]-1-idx[i][j-1])});
                    a.push_back({idx[i][j],1});
                }
                pair<int,pair<int,int>>val = solve(a);
                //cout << sorted[i] << " " << val.first << "\n";
                if(val.first>mx){
                    mx = val.first;
                    p = val.second;
                    ans = i;
                }
            }
        }
        cout << sorted[ans] << " " << p.first << " " << p.second << "\n";
    }
    return 0;
}