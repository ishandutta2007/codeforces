#include <bits/stdc++.h>
using namespace std;
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        vector<int>psa(n+1);
        for(int i = 1; i<=n; i++){
            psa[i] = psa[i-1]+arr[i];
        }
        vector<pair<int,int>>vals;
        vals.push_back({0,0});
        for(int d = 1; d<=n; d++){
            for(int i = d; i<=n; i++){
                vals.push_back({d,psa[i]-psa[i-d]});
            }
        }
        vector<int>suf(vals.size()+1);
        suf[vals.size()] = -(int)1e9;
        for(int i = vals.size()-1; i>=1; i--){
            suf[i] = max(suf[i+1],vals[i].second);
        }
        int cur = 0;
        int mx = 0;
        cout << max(suf[1],0) << " ";
        for(int j = 1; j<=n; j++){
            while(cur<vals.size()){
                cur++;
                mx = max(mx,vals[cur].second+x*vals[cur].first);
                if(vals[cur].first==j){
                    cout << max(mx,suf[cur]+x*j) << " ";
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}