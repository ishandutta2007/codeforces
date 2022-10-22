#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int mat[1005][1005];
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
        }
    }
    queue <pair <int, int>> q;
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(mat[i][j] && mat[i+1][j] && mat[i+1][j+1] && mat[i][j+1]){
                q.push({i, j});
                res[i][j] = res[i+1][j] = res[i][j+1] = res[i+1][j+1] = 1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(mat[i][j] != res[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    cout << q.size() << "\n";
    while(!q.empty()){
        cout << q.front().first << " " << q.front().second << "\n";
        q.pop();
    }
    return 0;
}