//Krzysztof Boryczka
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

int n;
vi G[N];
bool block[N];
int dpth[N], rozm[N], par[N], sum;
int dist[20][N];
int ans[N];

void dfs(int v, int p){
	rozm[v]=1;
	for(auto x: G[v]){
		if(x!=p && !block[x]){
			dfs(x, v);
			rozm[v]+=rozm[x];
		}
	}
}

int centroid(int v, int p){
	for(auto x: G[v]){
		if(x!=p && !block[x] && rozm[x]>sum/2){
			return centroid(x, v);
		}
	}
	return v;
}

void distdfs(int v, int p, int gleb){
	dist[gleb][v]=dist[gleb][p]+1;
	for(auto x: G[v]){
		if(x!=p && !block[x]){
			distdfs(x, v, gleb);
		}
	}
}

void decomp(int v, int p){
	dfs(v, v);
	sum=rozm[v];
	v=centroid(v, v);
	par[v]=p;
	dpth[v]=dpth[p]+1;

	dist[dpth[v]][v]=-1;
	distdfs(v, v, dpth[v]);

	block[v]=1;
	for(auto x: G[v]){
		if(!block[x]){
			decomp(x, v);
		}
	}
}

void paint(int v){
	int st=v;
	while(v){
		ans[v]=min(ans[v], dist[dpth[v]][st]);
		v=par[v];
	}
}

int query(int v){
	int st=v, ret=inf;
	while(v){
		ret=min(ret, dist[dpth[v]][st]+ans[v]);
		v=par[v];
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b, m;
	cin>>n>>m;
	FOR(i, 2, n){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	decomp(1, 0);
	memset(ans, inf, sizeof(ans));
	paint(1);
	FOR(i, 1, m){
		cin>>a>>b;
		if(a==1) paint(b);
		else cout<<query(b)<<ent;
	}
	return 0;
}