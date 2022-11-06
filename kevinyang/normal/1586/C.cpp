#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<int>>arr(n+1,vector<int>(m+1));
    for(int i = 1; i<=n; i++){
        string s;
        cin >> s;
        for(int j = 1; j<=m; j++){
            if(s[j-1]=='X'){
                arr[i][j] = 1;
            }
        }
    }
    vector<int>psa(m+1);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(arr[i-1][j]==1&&arr[i][j-1]==1){
                psa[j]++;
            }
        }
    }
    for(int j = 1; j<=m; j++){
        psa[j]+=psa[j-1];
    }
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        int v = psa[b]-psa[a];
        if(v)cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}