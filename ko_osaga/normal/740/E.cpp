#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, lint> pi;

int n, a[300005];
lint b[300005];

struct seg{
	struct node{
		int opt, lopt, ropt, lp, lm, rp, rm, sz;
	}tree[1050000];
	node merge(node &l, node &r){
		node x;
		x.sz = l.sz + r.sz;
		x.opt = max({l.opt, r.opt, l.ropt + r.lm, l.rp + r.lopt});
		x.lp = l.lp + (l.lp == l.sz ? r.lp : 0);
		x.lm = l.lm + (l.lm == l.sz ? r.lm : 0);
		x.rp = r.rp + (r.rp == r.sz ? l.rp : 0);
		x.rm = r.rm + (r.rm == r.sz ? l.rm : 0);
		x.lopt = max(l.lopt + (l.lopt == l.sz ? r.lm : 0),
					l.lp + (l.lp == l.sz ? r.lopt : 0));
		x.ropt = max(r.ropt + (r.ropt == r.sz ? l.rp : 0),
					r.rm + (r.rm == r.sz ? l.ropt : 0));
		return x;
	}
	node make(lint x){
		return (node){x != 0, x != 0, x != 0, x > 0, x < 0, x > 0, x < 0, 1};
	}
	void init(int s, int e, int p, lint *x){
		if(s == e){
			tree[p] = make(x[s]);
			return;
		}
		int m = (s+e)/2;
		init(s, m, 2*p, x);
		init(m+1, e, 2*p+1, x);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
	void add(int pos, int s, int e, int p, lint v){
		if(s == e){
			tree[p] = make(v);
			return;
		}
		int m = (s+e)/2;
		if(pos <= m) add(pos, s, m, 2*p, v);
		else add(pos, m+1, e, 2*p+1, v);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
}seg;

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(i > 1) b[i-1] = a[i] - a[i-1];
	}
	if(n > 1) seg.init(1, n-1, 1, b);
	int q;
	scanf("%d",&q);
	if(n == 1){
		while(q--) puts("1");
		return 0;
	}
	while(q--){
		int l, r, x;
		scanf("%d %d %d",&l,&r,&x);
		if(l-1 > 0){
			b[l-1] += x;
			seg.add(l-1, 1, n-1, 1, b[l-1]);
		}
		if(r < n){
			b[r] -= x;
			seg.add(r, 1, n-1, 1, b[r]);
		}
		printf("%d\n", seg.tree[1].opt + 1);
	}
}