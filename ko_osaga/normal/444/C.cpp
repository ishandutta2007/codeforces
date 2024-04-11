#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, m;

struct seg{
	lint tree[270000], lazy[270000];
	void lazydown(int x, int s, int e){
		int m = (s+e)/2;
		tree[2*x] += lazy[x] * (m - s + 1);
		tree[2*x+1] += lazy[x] * (e - m);
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}
	void add(int s, int e, int ps, int pe, int p, int v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p] += 1ll * (pe - ps + 1) * v;
			lazy[p] += v;
			return;
		}
		lazydown(p, ps, pe);
		int pm = (ps + pe) / 2;
		add(s, e, ps, pm, 2*p, v);
		add(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = tree[2*p] + tree[2*p+1];
	}
	lint query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return 0;
		if(s <= ps && pe <= e) return tree[p];
		lazydown(p, ps, pe);
		int pm = (ps + pe) / 2;
		return query(s, e, ps, pm, 2*p) + query(s, e, pm+1, pe, 2*p+1);
	}
}seg;


struct node{
	int tag;
}tree[270000];

void push(int x){
	if(tree[x].tag){
		tree[2*x].tag = tree[x].tag;
		tree[2*x+1].tag = tree[x].tag;
		tree[x].tag = 0;
	}
}

void pull(int x){
	if(tree[2*x].tag == tree[2*x+1].tag){
		tree[x].tag = tree[2*x].tag;
		tree[2*x].tag = tree[2*x+1].tag = 0;
	}
}

void init(int s, int e, int p){
	if(s == e){
		tree[p].tag = s;
		return;
	}
	int m = (s+e)/2;
	init(s, m, 2*p);
	init(m+1, e, 2*p+1);
	pull(p);
}

void paint(int s, int e, int ps, int pe, int p, int v){
	if(e < ps || pe < s) return;
	if(s <= ps && pe <= e && tree[p].tag){
		int val = abs(tree[p].tag - v);
		tree[p].tag = v;
		seg.add(ps, pe, 1, n, 1, val);
		return;
	}
	int pm = (ps + pe) / 2;
	push(p);
	paint(s, e, ps, pm, 2*p, v);
	paint(s, e, pm+1, pe, 2*p+1, v);
	pull(p);
}

int main(){
	cin >> n >> m; init(1,n, 1);
	for(int i=0; i<m; i++){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int l, r, x;
			scanf("%d %d %d",&l,&r,&x);
			paint(l,r,1,n,1,x);
		}
		else{
			int s, e;
			scanf("%d %d",&s,&e);
			printf("%lld\n",seg.query(s, e, 1, n, 1));
		}
	}
}