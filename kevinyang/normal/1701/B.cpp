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
        vector<bool>vis(n+1);
        cout << "2\n";
        for(int i = 1; i<=n; i++){
            if(vis[i])continue;
            int k = i;
            while(true){
                cout << k << " ";
                vis[k] = true;
                k*=2;

                if(k>n)break;
            }
        }
        cout << "\n";
    }
    return 0;
}