#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
ll n, l, a[5005], b[5005], sz[5005], dt[5005][5005][2], tmp[5005][2], ans;
vector<ll> adj[5005];

void solve (ll X) {
	sz[X] = 1;
	dt[X][0][0] = 0;
	dt[X][1][0] = a[X];
	dt[X][1][1] = a[X] - b[X];
	for(auto &N : adj[X]) {
		solve(N);
		ll cmx[3] = {-1, -1};
		for(ll B=0;B<2;B++) for(ll C=0;C<=B;C++) {
			for(ll i=0;i<=sz[X];i++) for(ll j=0;j<=sz[N];j++) {
				if(cmx[B] < i+j) {cmx[B] = i+j; tmp[cmx[B]][B] = inf;}
				tmp[i+j][B] = min(tmp[i+j][B], dt[X][i][B]+dt[N][j][C]);
			}
		}
		for(ll B=0;B<2;B++) {
			for(ll i=0;i<=cmx[B];i++) {
				dt[X][i][B] = min(dt[X][i][B], tmp[i][B]);
			}
		}
		sz[X] += sz[N];
	}
}

int main()
{
	scanf("%lld%lld",&n,&l);
	for(ll i=1;i<=n;i++) {
		scanf("%lld%lld",&a[i],&b[i]);
		if(i > 1) {
			ll P;
			scanf("%lld",&P);
			adj[P].push_back(i);
		}
		for(ll j=0;j<=n;j++) {
			dt[i][j][0] = inf;
			dt[i][j][1] = inf;
		}
	}
	solve(1);
	for(ll j=0;j<2;j++) {
		for(ll i=1;i<=n;i++) {
			if(dt[1][i][j] <= l) ans = max(ans, i);
		}
	}
	printf("%lld\n",ans);
}