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

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
int n, m, k, v, ans;
vii G[N];
ll dist[N];
bool vis[N];

void solve(){
	int a, b, c;
	cin>>n>>m>>k;
	FOR(i, 1, m){
		cin>>a>>b>>c;
		G[a].pb({b, c*2});
		G[b].pb({a, c*2});
	}
	FOR(i, 1, k){
		cin>>b>>c;
		G[1].pb({b, c*2+1});
		G[b].pb({1, c*2+1});
	}
	memset(dist, inf, sizeof(dist));
	dist[1]=0;
	q.push({0, 1});
	while(!q.empty()){
		v=q.top().nd;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		ans+=dist[v]&1;
		dist[v]-=dist[v]&1;
		for(auto &u: G[v]){
			if(dist[u.st]>dist[v]+u.nd){
				dist[u.st]=dist[v]+u.nd;
				q.push({dist[u.st], u.st});
			}
		}
	}
	cout<<k-ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}