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
int dpth[N], rozm[N];
int par[N], sum;

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

void decomp(int v, int p){
	dfs(v, v);
	sum=rozm[v];
	v=centroid(v, v);
	par[v]=p;
	dpth[v]=dpth[p]+1;
	block[v]=1;
	for(auto x: G[v]){
		if(!block[x]){
			decomp(x, v);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b;
	cin>>n;
	FOR(i, 2, n){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	decomp(1, 0);
	FOR(i, 1, n) cout<<(char)(dpth[i]+'A'-1)<<sp;
	cout<<ent;
	return 0;
}