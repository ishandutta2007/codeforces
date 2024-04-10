#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int mat[1005][1005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=m; j++){
            if(s[j-1] == 'W') mat[i][j] = 1;
            else if(s[j-1] == 'S') mat[i][j] = 2;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(mat[i][j] == 2){
                if(mat[i+1][j] == 1 || mat[i-1][j] == 1 || mat[i][j-1] == 1 || mat[i][j+1] == 1){
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }
    cout << "Yes\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!mat[i][j]) cout << "D";
            else if(mat[i][j] == 1) cout << "W";
            else cout << "S";
        }
        cout << "\n";
    }
    return 0;
}