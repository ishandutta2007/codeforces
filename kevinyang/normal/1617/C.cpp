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
        vector<int>arr(n+1);
        bool f = true;
        int cnt = 0;
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        multiset<int>s;
        for(int i = 1; i<=n; i++){
            s.insert(arr[i]);
        }
        vector<bool>vis(n+1);
        for(int i = 1; i<=n; i++){
            if(s.find(i)!=s.end()){
                s.erase(s.lower_bound(i));
                vis[i] = true;
                cnt++;
            }
        }
        for(int i = 1; i<=n; i++){
            if(vis[i])continue;
            if(s.lower_bound(2*i+1)!=s.end()){
                s.erase(s.lower_bound(2*i+1));
            }
            else{
                f = false;
            }
        }
        if(!f){
            cout << "-1\n";
        }
        else{
            cout << n-cnt << "\n";
        }
    }
    return 0;
}