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
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN][2];
int x, y, z, k;
int dp[maxN][2];

vector<int> vc[maxN];

void calc(int node, int par){
    dp[node][0] = 0; dp[node][1] = 0;
    for(int child : vc[node]){
        if(child == par) continue;
        calc(child, node);
        int v[2]; v[0] = 0; v[1] = 0;
        for1(g, 0, 1){
            for1(h, 0, 1){
                v[g] = max(v[g], dp[child][h] + abs(a[node][g] - a[child][h]));
            }
        }
        dp[node][0] += v[0];
        dp[node][1] += v[1];
        
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n){
            vc[i].clear();
            cin >> a[i][0] >> a[i][1];
        }
        for1(i, 2, n){
            cin >> x >> y;
            vc[x].pb(y);
            vc[y].pb(x);
        }
        calc(1, 0);
        cout << max(dp[1][0], dp[1][1]) << endl;
        // for1(i, 1, n){
        //     cout << dp[i][0] << " " << dp[i][1] << endl;
        // }
    }
}