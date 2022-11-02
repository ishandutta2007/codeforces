#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int N = 100005;
int n, m, h, cc, wh[N], a[N], ans;
bool vis[N];

vector<int> adj[N], rev[N], scc[N], ord;

void add (int A, int B) {
	adj[A].push_back(B);
	rev[B].push_back(A);
}

void dfs (int X) {
	vis[X] = true;
	for(auto &T : adj[X]) {
		if(!vis[T]) dfs(T);
	}
	ord.push_back(X);
}

void rdfs (int X) {
	scc[cc].push_back(X);
	wh[X] = cc;
	vis[X] = true;
	for(auto &T : rev[X]) {
		if(!vis[T]) rdfs(T);
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++) {
		int A,B;
		scanf("%d%d",&A,&B);
		if((a[A]+1)%h == a[B]) add(A, B);
		if((a[B]+1)%h == a[A]) add(B, A);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	fill(vis+1, vis+1+n, false);
	while(!ord.empty()) {
		int i = ord.back(); ord.pop_back();
		if(!vis[i]) {cc++; rdfs(i);}
	}
	for(int i=1;i<=cc;i++) {
		bool F = true;
		for(auto &C : scc[i]) for(auto &T : adj[C]) {
			if(wh[T] != i) F = false;
		}
		if(F && (!ans || scc[i].size() < scc[ans].size())) ans = i;
	}
	printf("%d\n",scc[ans].size());
	for(auto &T : scc[ans]) printf("%d ", T);
	puts("");
}