#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int mod = 998244353;

struct disj{
	int pa[MAXN];
	int sz[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	void toggle(int x){
		sz[find(x)]++;
	}
	int getsz(int x){ return sz[find(x)]; }
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; sz[p] += sz[q]; return 1;
	}
}disj;

struct edg{int s, e, x; bool operator<(const edg &e)const{ return x < e.x; }}E[MAXN];

int n, m, k;

int main(){
	scanf("%d %d %d",&n,&m,&k);
	disj.init(n);
	for(int i=0; i<k; i++){
		int x; scanf("%d",&x);
		disj.toggle(x);
	}
	for(int i=0; i<m; i++) scanf("%d %d %d",&E[i].s,&E[i].e,&E[i].x);
	sort(E, E + m);
	for(int i=0; i<m; i++){
		if(disj.uni(E[i].s, E[i].e)){
			if(disj.getsz(E[i].s) == k){
				for(int j=0; j<k; j++) printf("%d ", E[i].x);
				return 0;
			}
		}
	}
}