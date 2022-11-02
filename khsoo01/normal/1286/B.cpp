#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const int N = 2005;

int n, a[N], c[N], x[N];
vector<int> adj[N], id[N];

void calc (int I) {
	c[I] = 1;
	for(auto &T : adj[I]) {
		calc(T);
		c[I] += c[T];
	}
}

void solve (int I) {
	if(a[I] >= id[I].size()) {
		puts("NO");
		exit(0);
	}
	x[I] = id[I][a[I]];
	int J = 0;
	for(auto &T : adj[I]) {
		while(id[T].size() < c[T]) {
			if(J != a[I]) {
				id[T].push_back(id[I][J]);
			}
			J++;
		}
		solve(T);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		int T;
		scanf("%d%d",&T,&a[i]);
		adj[T].push_back(i);
	}
	vector<int> V;
	for(int i=0;i<=n;i++) {
		id[0].push_back(i);
	}
	calc(0);
	solve(0);
	puts("YES");
	for(int i=1;i<=n;i++) {
		printf("%d ",x[i]);
	}
}