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
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        vector<int>sorted;
        for(int i = 1; i<=n; i++){
            sorted.push_back(arr[i]);
        }
        sorted.push_back(0);
        sort(sorted.begin(),sorted.end());
        for(int i = 1; i<=n; i++){
            arr[i] = lower_bound(sorted.begin(),sorted.end(),arr[i])-sorted.begin();
        }
        vector<int>freq(n+1);
        for(int i = 1; i<=n; i++){
            freq[arr[i]]++;
        }
        vector<vector<int>>vals(n+1);
        vector<vector<int>>bad(n+1);
        vector<bool>vis(n+1);
        vector<int>lens;
        for(int i = 1; i<=n; i++){
            if(!vis[arr[i]]){
                vals[freq[arr[i]]].push_back(arr[i]);
                vis[arr[i]] = true;
            }
        }
        for(int i = 0; i<m; i++){
            int x,y;
            cin >> x >> y;
            x = lower_bound(sorted.begin(),sorted.end(),x)-sorted.begin();
            y = lower_bound(sorted.begin(),sorted.end(),y)-sorted.begin();
            bad[x].push_back(y);
            bad[y].push_back(x);
        }
        for(int i = 1; i<=n; i++){
            bad[i].push_back(i);
            sort(bad[i].begin(),bad[i].end());
            reverse(bad[i].begin(),bad[i].end());
            sort(vals[i].begin(),vals[i].end());
            reverse(vals[i].begin(),vals[i].end());
            if(vals[i].size()){
                lens.push_back(i);
            }
            /*
            for(int nxt: bad[i]){
                cout << nxt << " ";
            }
            cout << "\n";
            for(int nxt: vals[i]){
                cout << nxt << " ";
            }
            cout << "\n";
            */
        }
        for(int i = 1; i<=n; i++){
            vis[i] = false;
        }
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(vis[arr[i]])continue;
            vis[arr[i]] = true;
            for(int len: lens){
                int cur = 0;
                for(int j = 0; j<vals[len].size(); j++){
                    while(cur<bad[arr[i]].size()&&bad[arr[i]][cur]>vals[len][j]){
                        cur++;
                    }
                    if(cur<bad[arr[i]].size()&&bad[arr[i]][cur]==vals[len][j]){
                        continue;
                    }
                    ans = max(ans,(freq[arr[i]]+len)*(sorted[arr[i]]+sorted[vals[len][j]]));
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}