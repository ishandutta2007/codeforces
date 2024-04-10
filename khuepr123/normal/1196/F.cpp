/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define iii pair<int, ii>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int m;
iii pr[maxN];
vector<ii> vc[maxN];

map<ii, int> mp;

int d[maxN];

void solve(int root){
    memset(d, 1, sizeof(d));
    d[root] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, root));
    int lewd = 0;
    while(!pq.empty()){
        ii pr = pq.top(); pq.pop();
        int node = pr.se;
        if(d[node] == pr.fi){
            ++lewd;
            if(lewd == 402) break;
            mp[ii(min(node, root), max(node, root))] = d[node];
            for(ii cc : vc[node]){
                if(d[cc.se] > pr.fi + cc.fi){
                    d[cc.se] = pr.fi + cc.fi;
                    pq.push(ii(d[cc.se], cc.se));
                }
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for1(i, 1, m){
        cin >> x >> y >> z;
        vc[x].pb(ii(z, y));
        vc[y].pb(ii(z, x));
        pr[i].fi = z;
        pr[i].se = ii(min(x, y), max(x, y));
    }
    for1(i, 1, n){
        sort(vc[i].begin(), vc[i].end());
        while(vc[i].size() > 402) vc[i].pop_back();
    }
    sort(pr + 1, pr + m + 1);
    for1(i, 1, min(m, k)){
        solve(pr[i].se.fi);
        solve(pr[i].se.se);
    }
    vector<int> stlod;
    for(auto gg : mp) if(gg.se) stlod.pb(gg.se);
    sort(stlod.begin(), stlod.end());
    cout << stlod[k - 1] << endl;
    return 0;
}