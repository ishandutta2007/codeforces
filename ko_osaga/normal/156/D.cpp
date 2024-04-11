#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int mod;

lint ipow(lint x, lint p){
	lint ret = 1, piv = x % mod;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret % mod;
}

const int MAXN = 500005;
struct disj{
	int pa[MAXN], sz[MAXN];
	void init(int n){
		for(int i=0; i<=n; i++){
			pa[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p;
		sz[p] += sz[q];
		return 1;
	}
}disj;

int main(){
	int n, m;
	scanf("%d %d %d",&n,&m,&mod);
	disj.init(n);
	int c = n;
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		if(disj.uni(s, e)) c--;
	}
	if(c == 1){
		printf("%d\n", 1 % mod);
		return 0;
	}
	lint ret = ipow(n, c - 2);
	for(int i=1; i<=n; i++){
		if(disj.find(i) == i){
			ret *= disj.sz[i];
			ret %= mod;
		}
	}
	cout << ret;
}