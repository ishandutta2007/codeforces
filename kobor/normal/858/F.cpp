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

const int N=2e5+5;

int n, m;
vi G[N];
vector<pair<ii, int> > ans;
bool vis[N], seen[N];

bool dfs(int v, int p){
	vis[v]=seen[v]=1;
	int last=0;
	for(auto x: G[v]){
		if(x==p) continue;
		if(!vis[x] && !dfs(x, v)){
			if(!last) last=x;
			else{
				ans.pb({{last, v}, x});
				last=0;
			}
		}
		if(seen[x]){
			if(!last) last=x;
			else{
				ans.pb({{last, v}, x});
				last=0;
			}
		}
	}
	seen[v]=0;
	if(last && v!=p){
		ans.pb({{last, v}, p});
		return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b;
	cin>>n>>m;
	FOR(i, 1, m){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	FOR(i, 1, n){
		if(!vis[i]) dfs(i, i);
	}
	cout<<SIZE(ans)<<ent;
	for(auto x: ans) cout<<x.st.st<<sp<<x.st.nd<<sp<<x.nd<<ent;
	return 0;
}