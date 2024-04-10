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
        if(arr[1][1]=='1'){
            cout << "-1\n";
            continue;
        }
        cout << n*m << "\n";
        for(int i = n; i>=1; i--){
            for(int j = m; j>=1; j--){
                if(arr[i][j]=='0'){
                    cout << i << " " << j << " " << i << " " << j << "\n";
                }
                else{
                    if(i>1){
                        cout << i-1 << " " << j << " " << i << " " << j << "\n";
                    }
                    else{
                        cout << i << " " << j-1 << " " << i << " " << j << "\n";
                    }
                }
            }
        }
    }
    return 0;
}