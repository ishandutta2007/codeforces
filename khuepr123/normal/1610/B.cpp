/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
// #define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<ii> pr;
vector<int> vc[maxN];
int nxt[maxN];
bool saved;

void solve(int id){
    if(saved) return;
    id = a[id];
    vector<int> chim;
    for1(i, 1, n) if(a[i] != id) chim.pb(a[i]);
    vector<int> cac = chim;
    reverse(all(cac));
    saved = 1;
    for1(i, 0, (int)chim.size() - 1){
        if(chim[i] != cac[i]) saved = 0;
    }
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n) vc[i].clear();
        for1(i, 1, n){
            nxt[i] = 0; cin >> a[i];
            vc[a[i]].pb(i);
        }
        for1(i, 1, n){
            int md = (int)(vc[i].size() - 1) / 2;
            if(!vc[i].empty())
            for1(j, 0, md) nxt[vc[i][j]]
            = vc[i][(int)vc[i].size() - j - 1];
        }
        pr.clear();
        saved = 1;
        for1(i, 1, n) if(nxt[i]) pr.pb(ii(i, nxt[i]));
        for1(i, 0, (int)pr.size() - 2){
            if(pr[i].se < pr[i + 1].se){
                saved = 0;
                solve(pr[i].fi);
                solve(pr[i + 1].fi);
                break;
            }
        }
        if(saved) cout << "YES\n";
        else cout << "NO\n";

    }
}