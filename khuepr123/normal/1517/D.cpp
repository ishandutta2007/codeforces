#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 505;
const ll oo = 1e18 + 7;
int n, m;
int dp[maxN * maxN][25];
int x, y, z, k;
// node - length
vector<ii> vc[maxN * maxN];

int encode(int xx, int yy){
    return(xx - 1) * m + yy;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    if(k & 1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << "-1 ";
            }
            cout << endl;
        }
        return 0;
    }
    k /= 2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m; j++){
            cin >> z;
            x = encode(i, j);
            y = encode(i, j + 1);
            vc[x].pb(ii(z, y));
            vc[y].pb(ii(z, x));
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++){
            cin >> z;
            x = encode(i, j);
            y = encode(i + 1, j);
            vc[x].pb(ii(z, y));
            vc[y].pb(ii(z, x));
        }
    }
    for(int i = 1; i <= n * m; i++){
        dp[i][0] = 0;
    }
    for(int rg = 1; rg <= k; rg++){
        for(int i = 1; i <= n * m; i++){
            dp[i][rg] = oo;
            for(auto pr : vc[i]){
                dp[i][rg] = min(dp[i][rg], dp[pr.se][rg - 1ll] + pr.fi);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << dp[encode(i, j)][k] * 2ll << " ";
        }
        cout << endl;
    }
}