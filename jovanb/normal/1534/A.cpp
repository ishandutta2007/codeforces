#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool ima[2][2];

void solve(){
    int n, m;
    cin >> n >> m;
    ima[0][0] = ima[0][1] = ima[1][0] = ima[1][1] = 0;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            if(s[j] == 'R'){
                ima[0][(i+j)%2] = 1;
            }
            else if(s[j] == 'W'){
                ima[1][(i+j)%2] = 1;
            }
        }
    }
    if(ima[0][0] && ima[0][1]){
        cout << "NO\n";
        return;
    }
    if(ima[1][0] && ima[1][1]){
        cout << "NO\n";
        return;
    }
    if(ima[0][0] && ima[1][0]){
        cout << "NO\n";
        return;
    }
    if(ima[0][1] && ima[1][1]){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ima[0][(i+j)%2] || ima[1][(i+j+1)%2]) cout << "R";
            else if(ima[1][(i+j)%2] || ima[0][(i+j+1)%2]) cout << "W";
            else{
                if((i+j)%2) cout << "R";
                else cout << "W";
            }
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}