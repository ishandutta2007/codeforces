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

const int N=1e5+5;

int ile[N];
bool bad[N];
vi G[N];
int n, m;

void dfs(int v, int p){
    ile[v]*=(ile[v]+ile[p]);
    bad[v]=(ile[v]>m || bad[p]);
    for(auto &x: G[v]){
        if(x==p) continue;
        dfs(x, v);
    }
}

void solve(){
    int a, b, ans=0;
    cin>>n>>m;
    FOR(i, 1, n) cin>>ile[i];
    FOR(i, 2, n){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1, 0);
    FOR(i, 2, n) if(SIZE(G[i])==1 && !bad[i]) ans++;
    cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}