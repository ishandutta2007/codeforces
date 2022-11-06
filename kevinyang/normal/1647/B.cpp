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
        vector<vector<char>>arr(n+1,vector<char>(m+1));
        for(int i = 1; i<=n; i++){
            string s;
            cin >> s;
            for(int j = 1; j<=m; j++){
                arr[i][j] = s[j-1];
            }
        }
        bool f = true;
        for(int i = 2; i<=n; i++){
            for(int j = 2; j<=m; j++){
                int v = (arr[i][j]=='1')+(arr[i-1][j]=='1')+(arr[i][j-1]=='1')+(arr[i-1][j-1]=='1');
                if(v==3)f = false;
            }
        }
        cout << (f?"YES":"NO") << "\n";
    }
    return 0;
}