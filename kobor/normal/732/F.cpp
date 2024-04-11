//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int N=4e5+5;

int n, m, tim, nr;
vi G[N], sklad[N];
int low[N], in[N], jaka[N];
vi lece;
vii edg, mosty;
ii ans;
map<ii, ii> odp;
vector<pair<int, ii>> G2[N];

ii daj(int a, int b){
    return {min(a, b), max(a, b)};
}

void dfs(int v, int p){
    in[v]=low[v]=++tim;
    lece.pb(v);
    for(auto &x: G[v]){
        if(x==p) continue;
        if(in[x]) low[v]=min(low[v], in[x]);
        else dfs(x, v), low[v]=min(low[v], low[x]);
        if(!odp[daj(v, x)].st) odp[daj(v, x)]={v, x};
    }
    if(in[v]==low[v]){
        if(v!=1) mosty.pb({v, p});
        nr++;
        while(!jaka[v]){
            int u=lece.back();
            lece.pop_back();
            sklad[nr].pb(u);
            jaka[u]=nr;
        }
    }
}

void dfs2(int v, int p){
    for(auto &x: G2[v]){
        if(x.st==p) continue;
        odp[daj(x.nd.st, x.nd.nd)]={x.nd.nd, x.nd.st};
        dfs2(x.st, v);
    }
}

void solve(){
    int a, b;
    cin>>n>>m;
    FOR(i, 1, m){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
        edg.pb(daj(a, b));
    }
    dfs(1, 1);
    FOR(i, 1, n) ans=max(ans, {SIZE(sklad[jaka[i]]), i});
    for(auto &x: mosty) G2[jaka[x.st]].pb({jaka[x.nd], {x.st, x.nd}}), G2[jaka[x.nd]].pb({jaka[x.st], {x.nd, x.st}});
    dfs2(jaka[ans.nd], jaka[ans.nd]);
    cout<<ans.st<<ent;
    for(auto &x: edg) cout<<odp[x].st<<sp<<odp[x].nd<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}