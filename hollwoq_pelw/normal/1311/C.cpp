#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    string s;
    cin >> n >> m >> s;
    int a[n+1][26], res[26];
    for (int j = 0; j < 26; j ++){
        a[0][j] = 0;
        res[j] = 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 26; j ++){
            a[i+1][j] = a[i][j];
        }
        a[i+1][s[i]-'a'] ++;
    }
    int t;
    for (int i = 0; i < m; i++){
        cin >> t;
        for (int j = 0; j < 26; j++){
            res[j] += a[t][j];
        }
    }
    for (int j = 0; j < 26; j++){
        res[j] += a[n][j];
        cout << res[j] << ' ';
    }
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}