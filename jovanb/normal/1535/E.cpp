#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 300000;
const int MAXLOG = 19;

int par[MAXN+5][MAXLOG+1];
ll val[MAXN+5];
ll cost[MAXN+5];

ll res;

int nadji(int v){
    for(int j=MAXLOG; j>=0; j--) if(val[par[v][j]]) v = par[v][j];
    return v;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int q;
    cin >> q >> val[1] >> cost[1];
    int cnt = 1;
    for(int i=2; i<=q+1; i++){
        int t;
        cin >> t;
        if(t == 1){
            cin >> par[i][0] >> val[i] >> cost[i];
            par[i][0]++;
            for(int j=1; j<=MAXLOG; j++) par[i][j] = par[par[i][j-1]][j-1];
        }
        else{
            int v, x;
            cin >> v >> x;
            v++;
            int ox = x;
            res = 0;
            while(x && val[v]){
                int v1 = nadji(v);
                if(val[v1] >= x){
                    val[v1] -= x;
                    res += x*cost[v1];
                    x = 0;
                    break;
                }
                res += val[v1]*cost[v1];
                x -= val[v1];
                val[v1] = 0;
            }
            cout << ox-x << " " << res << endl;
        }
    }

    return 0;
}