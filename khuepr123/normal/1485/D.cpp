#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[505][505];
int res[505][505];

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if((i + j) % 2) res[i][j] = 720720;
            else res[i][j] = 720720 - pow(a[i][j], 4);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}