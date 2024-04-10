#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, l, dt[200005][6], sz[200005], ans, sum;
vector<ll> adj[200005];

void calc (ll cur, ll prv) {
	for(auto &nxt : adj[cur]) {
		if(nxt == prv) continue;
		calc(nxt, cur);
		for(int j=0;j<l;j++) {
			dt[cur][j] += dt[nxt][(j+l-1)%l];
		}
		sz[cur] += sz[nxt];
	}
	sz[cur]++;
	dt[cur][0]++;
	ans += sz[cur] * (n - sz[cur]);
}

void dfs (ll cur, ll prv, ll arr[]) {
	for(int i=1;i<l;i++) sum += (l-i) * arr[i];
	for(auto &nxt : adj[cur]) {
		if(nxt == prv) continue;
		ll nv[6];
		for(int i=0;i<l;i++) {
			nv[(i+1)%l] = (arr[i] - dt[nxt][(i+l-1)%l]);
		}
		for(int i=0;i<l;i++) {
			nv[i] += dt[nxt][i];
		}
		dfs(nxt, cur, nv);
	}
}

int main()
{
	scanf("%lld%lld",&n,&l);
	for(ll i=1;i<n;i++) {
		ll A, B;
		scanf("%lld%lld",&A,&B);
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	calc(1, 0);
	dfs(1, 0, dt[1]);
	printf("%lld\n",(ans + sum/2)/l);
}