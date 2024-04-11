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
const int M=2e6;

int n, q, glob;
int val[N], lp[M+5], ans[N], in[N], rin[N]={-1};
vi fact[N], G[N];
vi primes[M+5];

void factorise(int v){
	int pom=val[v];
	fact[v].clear();
	if(pom==1) return;
	while(lp[pom]){
		if(!SIZE(fact[v]) || lp[pom]!=fact[v].back()) fact[v].pb(lp[pom]);
		pom/=lp[pom];
	}
	if(!SIZE(fact[v]) || pom!=fact[v].back()) fact[v].pb(pom);
}

void predfs(int v=1){
	in[v]=++glob;
	rin[glob]=v;
	for(auto &u: G[v]) if(!in[u]) predfs(u);
}

void dfs(int v=1){
	ans[v]=0;
	for(auto &x: fact[v]) if(SIZE(primes[x])) ans[v]=max(ans[v], primes[x].back());
	for(auto &x: fact[v]) primes[x].pb(in[v]);
	for(auto &u: G[v]){
		if(in[u]>in[v]) dfs(u);
	}
	for(auto &x: fact[v]) primes[x].pop_back();
}

void solve(){
	int a, b;
	cin>>n>>q;
	FOR(i, 1, n) cin>>val[i];
	FOR(i, 2, n){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	for(int i=2; i*i<=M; i++){
		if(lp[i]) continue;
		for(int j=i*i; j<=M; j+=i) if(!lp[j]) lp[j]=i;
	}
	FOR(i, 1, n) factorise(i);
	predfs();
	dfs();
	FOR(i, 1, q){
		cin>>a>>b;
		if(a==1) cout<<rin[ans[b]]<<ent;
		else{
			cin>>a;
			val[b]=a;
			factorise(b);
			dfs();
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}