#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

const int N = 2e5+10;
int r[N];
int par[N];
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
vector<int> sw[N];
vi con[N];
int col[N], vis[N];
bool is_bipartite(int s){
	queue<int> q;
	q.push(s);
	col[s] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int v:con[u]){
			if(col[v] && col[v] != 3 - col[u]) return 0;
			if(!col[v]){
				col[v] = 3 - col[u];
				q.push(v);
			}
		}
	}
	return 1;
}
bool bipar(int n){
	for(int i = 1;i<=n;i++) if(!col[i]) if(!is_bipartite(i)) return 0;
	return 1;
}
int main(){
	int n,m,x,k;
	sd(n), sd(m);
	rep(i,1,n+1) sd(r[i]);
	rep(i,1,m+1){
		sd(x);
		rep(j,1,x+1){
			sd(k);
			sw[k].pb(i);
		}
	}
	memset(par,-1,sizeof par);
	for(int i = 1;i<=n;i++){
		if(r[i] == 1) merge(sw[i][0], sw[i][1]);
	}
	for(int i = 1;i<=n;i++){
		if(r[i] == 0 && (root(sw[i][0]) == root(sw[i][1]))){
			printf("NO");
			return 0;
		}
		if(r[i] == 0){
			int a = sw[i][0], b = sw[i][1];
			a = root(a), b = root(b);
			con[a].pb(b); con[b].pb(a);
		}
	}
	if(bipar(m)) printf("YES");
	else printf("NO");
}