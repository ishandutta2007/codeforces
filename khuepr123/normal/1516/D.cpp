#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
vector<int> fac[maxN];
int direct[maxN][20];
int dr[maxN];
vector<int> vv[maxN];



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int o; cin >> o;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 2; i <= maxN; i++){
        if(fac[i].size() == 0){
            for(int j = i; j <= maxN; j += i){
                fac[j].pb(i);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(auto j : fac[a[i]]){
            vv[j].pb(i);
        }
        dr[i] = n + 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < vv[i].size(); j++){
            dr[vv[i][j - 1]] = min(dr[vv[i][j - 1]], vv[i][j]);
        }
    }
    int miner = n + 1;
    for(int i = n; i > 0; i--){
        int mn = min(miner, dr[i]);
        dr[i] = mn;
        miner = mn;
    }
    for(int i = 1; i <= n; i++){
        direct[i][0] = dr[i];
    }
    direct[n + 1][0] = n + 2;
    direct[n + 2][0] = n + 2;
    for(int rg = 1; rg < 18; rg++){
        for(int i = 1; i <= n + 2; i++){
            direct[i][rg] = direct[direct[i][rg - 1]][rg - 1];
        }
    }
    while(o--){
        cin >> x >> y;
        int cur = 17;
        int ans = 0;
        int node = x;
        while(cur != -1){
            if(direct[node][cur] > y) cur--;
            else{
                ans += (1 << cur);
                node = direct[node][cur];
            }
        }
        cout << ans + 1 << endl;
    }
}