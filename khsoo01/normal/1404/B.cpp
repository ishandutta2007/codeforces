#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a, b, da, db, d[N];
vector<int> adj[N];

void dfs (int C, int P) {
	d[C] = d[P] + 1;
	for(auto &T : adj[C]) {
		if(T == P) continue;
		dfs(T, C);
	}
}

void solve () {
	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
	for(int i=1;i<n;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	d[0] = -1;
	dfs(b, 0);
	bool als = false;
    if(d[a] <= da) als = true;
    int j = 0;
    for(int i=1;i<=n;i++) {
		if(d[i] > d[j]) j = i;
    }
    d[0] = -1;
    dfs(j, 0);
    int mx = 0;
    for(int i=1;i<=n;i++) {
		mx = max(mx, d[i]);
    }
    if(min(db, mx) <= 2*da) als = true;
    if(als) puts("Alice");
    else puts("Bob");
    for(int i=1;i<=n;i++) {
		adj[i].clear();
    }
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--) solve();
}