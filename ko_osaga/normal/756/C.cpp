#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

struct seg{
	int tree[270000], lazy[270000];
	void lazydown(int p){
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
		tree[2*p] += lazy[p];
		tree[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	void add(int s, int e, int ps, int pe, int p, int v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p] += v;
			lazy[p] += v;
			return;
		}
		lazydown(p);
		int pm = (ps+pe)/2;
		add(s, e, ps, pm, 2*p, v);
		add(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = min(tree[2*p], tree[2*p+1]);
	}
	int query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return 1e9;
		if(s <= ps && pe <= e) return tree[p];
		lazydown(p);
		int pm = (ps + pe) / 2;
		return min(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
	}
}seg;

int n, a[100005];
int fl = 0;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int p, t;
		scanf("%d %d",&p,&t);
		if(t == 0){
			fl--;
			seg.add(p, n, 0, n, 1, -1);
		}
		else{
			int x;
			scanf("%d",&x);
			a[p] = x;
			fl++;
			seg.add(p, n, 0, n, 1, 1);
		}
		if(seg.query(0, n, 0, n, 1) >= fl){
			puts("-1");
			continue;
		}
		int s = 0, e = n;
		while(s != e){
			int m = (s+e+1)/2;
			if(seg.query(m, n, 0, n, 1) >= fl) e = m-1;
			else s = m;
		}
		printf("%d\n", a[s+1]);
	}
}