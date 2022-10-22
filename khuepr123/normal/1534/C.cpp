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
const int maxN = 400005;
const ll oo = 1e18 + 7;
int n, a[3][maxN];
int x, y, z, k;
int par[maxN];

int find(int i){
    if(i == par[i]) return i;
    else return par[i] = find(par[i]);
}

void unite(int i, int j){
    par[find(i)] = find(j);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, 2){
            for1(j, 1, n){
                cin >> a[i][j];
                par[j] = j;
            }
        }
        for1(j, 1, n){
            unite(a[1][j], a[2][j]);
        }
        int ds = 0;
        for1(i, 1, n){
            if(i == par[i]) ++ds;
        }
        int ans = 1;
        while(ds--){
            ans *= 2;
            ans %= mod;
        }
        cout << ans << endl;
    }
}