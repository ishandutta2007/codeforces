#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, a[200005], deg[200005];
ll ans[200005];

void solve ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		deg[i] = 0;
	}
	for(int i=1;i<n;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		deg[A]++; deg[B]++;
	}
	ll cur = 0;
	priority_queue<pii> pq;
	for(int i=1;i<=n;i++) {
		cur += 1ll * a[i] * deg[i];
		if(deg[i] > 1) pq.push({-a[i], i});
	}
	int X = n-1;
	ans[X] = cur;
	while(!pq.empty()) {
		int I = pq.top().Y;
		pq.pop();
		while(deg[I] > 1) {
			cur -= a[I];
			ans[--X] = cur;
			--deg[I];
		}
	}
	for(int i=1;i<=n-1;i++) {
		printf("%lld ",ans[i]);
	}
	puts("");
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--) solve();
}