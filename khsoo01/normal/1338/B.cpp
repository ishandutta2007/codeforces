#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const int N = 100005;

int n, a[N], c[2], d;
vector<int> adj[N];

void calc (int C, int P) {
	a[C] = (a[P] ^ 1);
	for(auto &T : adj[C]) {
		if(T == P) continue;
		calc(T, C);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	calc(1, 0);
	for(int i=1;i<=n;i++) {
		if(adj[i].size() == 1) c[a[i]]++;
	}
	for(int i=1;i<=n;i++) {
		int X = 0;
		for(auto &T : adj[i]) {
			if(adj[T].size() == 1) X++;
		}
		if(X > 0) d += X-1;
	}
	printf("%d %d\n", (c[0] == 0 || c[1] == 0 ? 1 : 3), n-1-d);
}