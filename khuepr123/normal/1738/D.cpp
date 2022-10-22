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
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<int> vc[maxN];
vector<int> ans;
vector<int> v[2];

void dfs(int node, bool h){
    for(int cc : vc[node]) v[h].pb(cc);
    h = !h;
    for(int cc : vc[node]) if(vc[cc].empty()) ans.pb(cc);
    for(int cc : vc[node]) if(!vc[cc].empty()){
        ans.pb(cc);
        dfs(cc, h);
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 0, n + 1) vc[i].clear();
        for1(i, 1, n){
            cin >> a[i];
            vc[a[i]].pb(i);
        }
        ans.clear();
        v[0].clear();
        v[1].clear();
        dfs(0, 0);
        dfs(n + 1, 0);
        if(v[0].size() && v[1].size()){
            if(v[0][0] > v[1][0]) swap(v[0], v[1]);
            x = 0;
            for(int cc : v[0]) x = max(x, cc);
        }
        else{
            if(vc[0].size()) x = 0;
            else x = n;
        }
        cout << x << endl;
        for(int cc : ans) cout << cc << " ";
        cout << endl;
    }
}