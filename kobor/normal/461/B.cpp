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

const int mod=1e9+7;
const int N=1e5+5;

int n, a;
int dp[N][2];
bool black[N];
vi G[N];

int pov(int base, int exp){
	int ret=1;
	while(exp){
		if(exp&1) ret=(ll)ret*base%mod;
		base=(ll)base*base%mod;
		exp>>=1;
	}
	return ret;
}

void dfs(int v=1){
	if(black[v]){
		dp[v][1]=1;
		for(auto &u: G[v]){
			dfs(u);
			dp[v][1]=(ll)dp[v][1]*(dp[u][0]+dp[u][1])%mod;
		}
	}
	else{
		dp[v][0]=1;
		for(auto &u: G[v]){
			dfs(u);
			dp[v][0]=(ll)dp[v][0]*(dp[u][0]+dp[u][1])%mod;
		}
		for(auto &u: G[v]){
			dp[v][1]=(dp[v][1]+(ll)dp[u][1]*dp[v][0]%mod*pov(dp[u][0]+dp[u][1], mod-2))%mod;
		}
	}
}

void solve(){
	cin>>n;
	FOR(i, 2, n){
		cin>>a;
		G[a+1].pb(i);
	}
	FOR(i, 1, n) cin>>black[i];
	dfs();
	cout<<dp[1][1]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}