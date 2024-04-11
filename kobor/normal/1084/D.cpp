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
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

int n;
vector<pair<int, ll> > G[300010];
ll cost[300010], dp[300010], best1[300010], best2[300010];
ll odp;

void dfs(int v, int p){
	dp[v]=cost[v];
	best1[v]=best2[v]=-INF;
	for(auto x: G[v]){
		if(x.st!=p){
			dfs(x.st, v);
			dp[v]=max(dp[v], dp[x.st]-x.nd+cost[v]);
			if(dp[x.st]-x.nd>best1[v]){
				best2[v]=best1[v];
				best1[v]=dp[x.st]-x.nd;
			}
			else if(dp[x.st]-x.nd>best2[v]){
				best2[v]=dp[x.st]-x.nd;
			}
		}
	}
	odp=max(odp, best1[v]+best2[v]+cost[v]);
	odp=max(odp, dp[v]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	ll val;
	cin>>n;
	FOR(i, 1, n){
		cin>>cost[i];
		dp[i]=cost[i];
	}
	FOR(i, 1, n-1){
		cin>>a>>b>>val;
		G[a].pb({b, val});
		G[b].pb({a, val});
	}
	dfs(1, -1);
	cout<<odp<<ent;
	return 0;
}