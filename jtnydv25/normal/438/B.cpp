#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], par[N], sz[N];
long long ans;

int root(int x){ return par[x] == x ? x : (par[x] = root(par[x]));}
long long get(int x){ return (x * 1ll * (x - 1));}
void merge(int a, int b){
	a = root(a); b = root(b);
	if(a == b) return;
	ans += get(sz[a] + sz[b]) - get(sz[a]) - get(sz[b]);
	par[a] = b;
	sz[b] += sz[a];
}

vector<int> nodes[N], con[N];
long long val[N];
int main(){
	for(int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		nodes[a[i]].push_back(i);
	}
	for(int i = 1; i <= m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		con[u].push_back(v);
		con[v].push_back(u);
	}
	long long ret = 0;
	val[N - 1] = ans;
	for(int i = N - 2; i >= 0; i--){
		for(int node : nodes[i]){
			for(int v : con[node]){
				if(a[v] >= i){
					merge(v, node);
				}
			}
		}
		val[i] = ans;
		ret += i * 1ll * (val[i] - val[i + 1]);
	}
	printf("%.17lf\n", ret / (n * 1.0 * (n - 1)));
}