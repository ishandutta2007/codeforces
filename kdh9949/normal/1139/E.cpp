#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define x first
#define y second

const int N = 5005;

int n, m, q, a[N], b[N], ub, vis[N], mat[N], rv[N];
vector<pii> e[N];

int f(int x){
	vis[x] = 1;
	for(pii i : e[x]){
		if((rv[i.x] < 0 || rv[i.x] >= ub) || (!vis[rv[i.x]] && f(rv[i.x]))){
			mat[x] = i.y;
			rv[i.x] = x;
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) scanf("%d", b + i);
	for(int i = 1; i <= n; i++) e[a[i]].emplace_back(b[i], i);
	fill(mat, mat + N, -1);
	fill(rv, rv + N, -1);
	ub = N;
	for(int i = 0; ; i++){
		fill(vis, vis + N, 0);
		if(!f(i)){ ub = i; break; }
	}
	scanf("%d", &q);
	for(int x; q--; ){
		scanf("%d", &x);
		int tt = 0;
		for(int i = 0; ; i++) if(e[a[x]][i].y == x){
			if(mat[a[x]] == x) tt = 1;
			e[a[x]].erase(e[a[x]].begin() + i);
			break;
		}
		if(!tt){ printf("%d\n", ub); continue; }
		mat[a[x]] = rv[b[x]] = -1;
		while(ub > a[x]){
			fill(vis, vis + N, 0);
			if(f(a[x])) break;
			ub--;
		}
		printf("%d\n", ub);
	}
}