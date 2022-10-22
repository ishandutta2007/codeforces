#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s[1005];
vector <pair <int, int>> a[3];

void solve(){
    int n;
    cin >> n;
    a[0].clear();
    a[1].clear();
    a[2].clear();
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j<n; j++){
            if(s[i][j] == 'X') a[(i+j)%3].push_back({i, j});
        }
    }
    int x = 0;
    if(a[1].size() < a[x].size()) x = 1;
    if(a[2].size() < a[x].size()) x = 2;
    for(auto c : a[x]){
        s[c.first][c.second] = 'O';
    }
    for(int i=0; i<n; i++){
        cout << s[i] << "\n";
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