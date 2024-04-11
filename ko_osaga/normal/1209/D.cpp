#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
const int MAXN = 200005;
const int mod = 1e9 + 7;
using lint = long long;
using pi = pair<lint, lint>;

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

int n, m;

int main(){
	scanf("%d %d",&n,&m);
	disj.init(n);
	int ret = 0;
	for(int i=0; i<m; i++){
		int x, y; scanf("%d %d",&x,&y);
		if(!disj.uni(x, y)) ret++;
	}
	cout << ret << endl;
}