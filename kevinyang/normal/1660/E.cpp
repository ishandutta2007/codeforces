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
        int cnt = 0;
        vector<vector<char>>mp(n,vector<char>(n));
        for(int i = 0; i<n; i++){
            string s;
            cin >> s;
            for(int j = 0; j<n; j++){
                mp[i][j] = s[j];
                if(mp[i][j]=='1')cnt++;
            }
        }
        int ans = n*n;
        for(int i = 0; i<n; i++){
            int c = 0;
            for(int j = 0; j<n; j++){
                int a = (i+j)%n; int b = j;
                if(mp[a][b]=='1')c++;
            }
            ans = min(ans,n-c+cnt-c);
        }
        cout << ans << "\n";
    }
    return 0;
}