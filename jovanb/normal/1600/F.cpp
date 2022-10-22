#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int graf[55][55];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        if(a > 50 || b > 50) continue;
        graf[a][b] = graf[b][a] = 1;
    }
    n = min(n, 50);
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            for(int k=j+1; k<=n; k++){
                for(int l=k+1; l<=n; l++){
                    for(int r=l+1; r<=n; r++){
                        int sum = graf[i][j] + graf[i][k] + graf[i][l] + graf[i][r] + graf[j][k] + graf[j][l] + graf[j][r] + graf[k][l] + graf[k][r] + graf[l][r];
                        if(sum == 10 || sum == 0){
                            cout << i << " " << j << " " << k << " " << l << " " << r << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}