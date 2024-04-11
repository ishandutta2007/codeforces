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

const int N=810;

int n, m, kk;
vector<pair<int, ii>> edg;
vi renum={0};
vector<ll> dist;
ll G[N][N];

int aft(int v){
	return lower_bound(renum.begin(), renum.end(), v)-renum.begin();
}

void solve(){
	int a, b, c;
	cin>>n>>m>>kk;
	FOR(i, 1, m){
		cin>>a>>b>>c;
		edg.pb({c, {a, b}});
	}
	sort(edg.begin(), edg.end());
	while(SIZE(edg)>kk) edg.pop_back();
	for(auto &x: edg) renum.pb(x.nd.st), renum.pb(x.nd.nd);
	sort(renum.begin(), renum.end());
	renum.erase(unique(renum.begin(), renum.end()), renum.end());
	n=SIZE(renum)-1;
	memset(G, inf, sizeof(G));
	for(auto &x: edg) G[aft(x.nd.st)][aft(x.nd.nd)]=G[aft(x.nd.nd)][aft(x.nd.st)]=x.st;
	FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
	FOR(i, 1, n) FOR(j, i+1, n) dist.pb(G[i][j]);
	sort(dist.begin(), dist.end());
	cout<<dist[kk-1]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}