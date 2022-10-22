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
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int h[maxN];
int cnt[maxN];
vector<int> vc[maxN];

void dfs_hei(int node, int pare){
    h[node] = 0;
    for(int cc : vc[node]) if(cc != pare){
        dfs_hei(cc, node);
        h[node] = max(h[node], h[cc]);
    }
    ++h[node];
    ++cnt[h[node]];
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    memset(cnt, 0, sizeof(cnt));
    for1(i, 2, n){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    dfs_hei(1, 0);
    int defeat = 0;
    int spent = 0;
    int cmi = 0;
    while(cnt[cmi + 1]) ++cmi;
    while(cmi > 0 && spent < k){
        ++spent;
        for1(i, 1, cmi) --cnt[i];
        defeat += cmi;
        while(!cnt[cmi]){
            --cmi;
            if(cmi == 0) break;
        }
    }
    // cout << defeat << " " << spent << endl;
    defeat = n - defeat; // number of blue
    x = n - spent - defeat;
    int ans = x * (spent - defeat);
    if(defeat){
        for1(i, 0, defeat){
            x = n - spent - i;
            ans = min(ans, x * (spent - i));
        }
    }
    if(defeat == 0){
        for1(i, spent, k) ans = max(ans, i * (n - i));
    }
    cout << ans << endl;
}