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
        vector<vector<int>>a(11,vector<int>(11));
        for(int i = 0; i<n; i++){
            string s;
            cin >> s;
            a[s[0]-'a'][s[1]-'a']++;
        }
        int ans = 0;
        for(int i = 0; i<11; i++){
            for(int j = 0; j<11; j++){
                for(int k = j+1; k<11; k++){
                    ans+=a[i][j]*a[i][k];
                    ans+=a[j][i]*a[k][i];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}