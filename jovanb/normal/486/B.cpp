#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int mat[1005][1005];
int nemar[1005];
int nemac[1005];
int imar[1005];
int imac[1005];
int res[1005][1005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> mat[i][j];
            if(!mat[i][j]){
                nemar[i] = 1;
                nemac[j] = 1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!nemar[i] && !nemac[j]){
                res[i][j] = 1;
                imar[i] = 1;
                imac[j] = 1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!imar[i] && !imac[j] && mat[i][j]){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}