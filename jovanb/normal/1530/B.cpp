#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int res[50][50];

int di[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<=n+2; i++){
        for(int j=0; j<=m+2; j++){
            res[i][j] = 0;
        }
    }
    for(int j=1; j<=m; j+=2) res[1][j] = 1;
    for(int i=2; i<=n; i++){
        int j = m;
        bool moze = 1;
        for(int k=0; k<9; k++) moze &= !res[i+di[k]][j+dj[k]];
        res[i][j] = moze;
    }
    for(int j=m-1; j>=1; j--){
        int i = n;
        bool moze = 1;
        for(int k=0; k<9; k++) moze &= !res[i+di[k]][j+dj[k]];
        res[i][j] = moze;
    }
    for(int i=n-1; i>=2; i--){
        int j = 1;
        bool moze = 1;
        for(int k=0; k<9; k++) moze &= !res[i+di[k]][j+dj[k]];
        res[i][j] = moze;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << res[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
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