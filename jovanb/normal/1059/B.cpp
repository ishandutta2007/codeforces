#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int mat[1005][1005];
int pref[1005][1005];
bool pnt[1005][1005];
int col[1005][1005];

int get(int i1, int j1, int i2, int j2){
    return pref[i2][j2]-pref[i1-1][j2]-pref[i2][j1-1]+pref[i1-1][j1-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=m; j++){
            if(s[j-1] == '#') mat[i][j] = 1;
            pref[i][j] = mat[i][j]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
        }
    }
    for(int i=2; i<n; i++){
        for(int j=2; j<m; j++){
            if(get(i-1, j-1, i+1, j+1)-mat[i][j] == 8)pnt[i][j] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(pnt[i-1][j-1] || pnt[i-1][j] || pnt[i-1][j+1] || pnt[i][j-1] || pnt[i][j+1] || pnt[i+1][j-1] || pnt[i+1][j] || pnt[i+1][j+1]) col[i][j] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(col[i][j] != mat[i][j]){cout << "NO"; return 0;}
        }
    }
    cout << "YES";
    return 0;
}