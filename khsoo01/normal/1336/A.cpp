#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const int N = 200005;

int n, k, dep[N], chi[N], par[N], deg[N];
vector<int> adj[N];

void calc (int C, int P) {
	par[C] = P;
	dep[C] = dep[P] + 1;
	chi[C] = 1;
	for(auto &T : adj[C]) {
		if(T == P) continue;
		calc(T, C);
		chi[C] += chi[T];
		deg[C]++;
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	calc(1, 0);
	priority_queue<pii> pq;
	for(int i=1;i<=n;i++) {
		if(!deg[i]) pq.push({dep[i] - chi[i], i});
	}
	ll ans = 0;
	while(k--) {
		int A, B, C;
		tie(A, B) = pq.top();
		pq.pop();
		ans += A;
		C = par[B];
		if(--deg[C] == 0) {
			pq.push({dep[C] - chi[C], C});
		}
	}
	printf("%lld\n", ans);
}