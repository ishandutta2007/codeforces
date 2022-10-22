#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);
        }
    }
    bool ck = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i > 0 && a[i][j] <= a[i-1][j]) {ck = 0; break;}
            if (j > 0 && a[i][j] <= a[i][j-1]) {ck = 0; break;}
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i > 0 && b[i][j] <= b[i-1][j]) {ck = 0; break;}
            if (j > 0 && b[i][j] <= b[i][j-1]) {ck = 0; break;}
        }
    }
    if (ck) cout << "Possible";
    else cout << "Impossible";
    return 0;
}