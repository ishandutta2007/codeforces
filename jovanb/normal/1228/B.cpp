#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int mora[1005][1005];

const int MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        for(int j=1; j<=x; j++){
            if(mora[i][j] == 2){
                cout << 0;
                return 0;
            }
            mora[i][j] = 1;
        }
        if(x == m) continue;
        if(mora[i][x+1] == 1){
            cout << 0;
            return 0;
        }
        mora[i][x+1] = 2;
    }
    for(int j=1; j<=m; j++){
        int x;
        cin >> x;
        for(int i=1; i<=x; i++){
            if(mora[i][j] == 2){
                cout << 0;
                return 0;
            }
            mora[i][j] = 1;
        }
        if(x == n) continue;
        if(mora[x+1][j] == 1){
            cout << 0;
            return 0;
        }
        mora[x+1][j] = 2;
    }
    int res = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!mora[i][j]) res = (res*2)%MOD;
        }
    }
    cout << res;
    return 0;
}