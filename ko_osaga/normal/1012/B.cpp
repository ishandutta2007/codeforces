#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 1000050;
const int mod = 1e9 + 7;

struct disj{
	int pa[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p); q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

int n, m, q;

int main(){
	scanf("%d %d %d",&n,&m,&q);
	disj.init(n + m);
	int ans = n + m - 1;
	for(int i=0; i<q; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		ans -= disj.uni(x, n + y);
	}
	cout << ans << endl;
}