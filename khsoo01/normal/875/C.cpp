#include<bits/stdc++.h>
#define boom {puts("No");exit(0);}
using namespace std;
const int N = 100005;

int n, m, vis[2*N], wh[2*N], cc;
vector<int> a[N], adj[2*N], rev[2*N], s, ans;
queue<int> q;

void adde (int A, int B) {
	adj[A].push_back(B);
	rev[B].push_back(A);
}

void getord (int S, int E, int D) {
	if(S == E) return;
	for(int i=S+1;i<=E;i++) {
		if(a[i-1].size() > D && a[i].size() <= D) boom;
	}
	if(a[E].size() <= D) return;
	int cs = S;
	for(int i=S+1;i<=E;i++) {
		if(a[i].size() <= D) continue;
		if(a[i-1].size() <= D) {cs = i; continue;}
		if(a[i-1][D] == a[i][D]) continue;
		int A = a[i-1][D], B = a[i][D];
		if(A > B) {adde(A, m+A); adde(m+B, B);}
		else {adde(A, B); adde(m+B, m+A);}
		getord(cs, i-1, D+1); cs = i;
	}
	getord(cs, E, D+1);
}

void dfs (int I) {
	vis[I] = true;
	for(auto &T : adj[I]) {
		if(!vis[T]) dfs(T);
	}
	s.push_back(I);
}

void rdfs (int I) {
	vis[I] = true;
	wh[I] = cc;
	for(auto &T : rev[I]) {
		if(!vis[T]) rdfs(T);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		int M, T;
		scanf("%d",&M);
		for(int j=1;j<=M;j++) {
			scanf("%d",&T);
			a[i].push_back(T);
		}
	}
	getord(1, n, 0);
	for(int i=1;i<=2*m;i++) if(!vis[i]) dfs(i);
	fill(vis+1, vis+1+2*m, false);
	for(int i=s.size();i--;) if(!vis[s[i]]) {++cc; rdfs(s[i]);}
	for(int i=1;i<=m;i++) {
		if(wh[i] == wh[i+m]) boom;
		if(wh[i] < wh[i+m]) ans.push_back(i);
	}
	puts("Yes");
	printf("%d\n",ans.size());
	for(auto &T : ans) printf("%d ",T);
}