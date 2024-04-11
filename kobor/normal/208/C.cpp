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

const int N=110;

int n, m;
vi G[N], Gin[N], Gout[N];
ll dpin[N], dpout[N];
int dist[N];
vi order;
set<ii> G_1, G_n;
ld ans[N];

void bfs(int st){
	queue<int> q;
	memset(dist, inf, sizeof(dist));
	dist[st]=0;
	q.push(st);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(auto &x: G[v]){
			if(dist[x]==inf){
				dist[x]=dist[v]+1;
				q.push(x);
			}
		}
	}
	FOR(v, 1, n) for(auto &x: G[v]) if(dist[v]+1==dist[x]) G_1.insert({v, x});
}

bool cmp(int v, int u){
	return dist[v]>dist[u];
}

void solve(){
	int a, b;
	cin>>n>>m;
	FOR(i, 1, m){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	bfs(n);
	swap(G_1, G_n);
	bfs(1);
	for(auto &p: G_1) if(G_n.count({p.nd, p.st})) Gout[p.st].pb(p.nd), Gin[p.nd].pb(p.st);

	FOR(i, 1, n) order.pb(i);
	sort(order.begin(), order.end(), cmp);
	dpout[n]++;
	for(auto &v: order) for(auto &x: Gout[v]) dpout[v]+=dpout[x];
	FOR(i, 1, n) swap(Gin[i], Gout[i]);
	swap(dpin, dpout);

	reverse(order.begin(), order.end());
	dpout[1]++;
	for(auto &v: order) for(auto &x: Gout[v]) dpout[v]+=dpout[x];
	FOR(i, 1, n) swap(Gin[i], Gout[i]);
	swap(dpin, dpout);

	FOR(v, 1, n) for(auto &x: Gout[v]){
		ans[v]+=(ld)dpin[v]*dpout[x];
		ans[x]+=(ld)dpin[v]*dpout[x];
	}
	FOR(v, 1, n) ans[v]/=dpin[n];

	cout<<fixed<<setprecision(10);
	cout<<*max_element(ans+1, ans+n+1)<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}