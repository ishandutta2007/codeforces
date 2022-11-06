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
        vector<int>a(n+5);
        vector<int>b(n+5);
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        for(int i = 1; i<=n; i++){
            cin >> b[i];
        }
        vector<pair<int,int>>ans;
        for(int i = 1; i<=n; i++){
            for(int j = 2; j<=n; j++){
                if(a[j-1]>a[j]){
                    swap(a[j-1],a[j]);
                    swap(b[j-1],b[j]);
                    ans.push_back({j-1,j});
                }
            }
        }
        int cur = 1;
        while(cur<=n){
            int idx = cur;
            while(idx<=n&&a[cur]==a[idx]){
                idx++;
            }
            idx--;
            for(int i = 1; i<=idx-cur+1; i++){
                for(int j = cur+1; j<=idx; j++){
                    if(b[j-1]>b[j]){
                        swap(b[j-1],b[j]);
                        ans.push_back({j-1,j});
                    }
                }
            }
            cur = idx+1;
        }
        bool f = true;
        for(int i = 2; i<=n; i++){
            if(b[i-1]>b[i])f = false;
        }
        if(f){
            cout << ans.size() << "\n";
            for(pair<int,int>nxt: ans){
                cout << nxt.first << " " << nxt.second << "\n";
            }
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}