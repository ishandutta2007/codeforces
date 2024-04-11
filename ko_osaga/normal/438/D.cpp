#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, m, a[100005];

struct bit{
	lint tree[100005];
	void add(int x, lint v){
		while(x <= n){
			tree[x] += v;
			x += x & -x;
		}
	}
	lint query(int x){
		lint ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit;

struct seg{
	pi tree[270000];
	int lim;
	void init(int n){
		fill(tree, tree + 270000, pi(-1e9, 1e9));
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void add(int x, int v){
		x += lim;
		tree[x] = pi(v, x-lim);
		while(x > 1){
			x >>= 1;
			tree[x] = max(tree[2*x], tree[2*x+1]);
		}
	}
	pi query(int s, int e){
		s += lim;
		e += lim;
		pi ret(-1, -1);
		while(s < e){
			if(s%2 == 1) ret = max(ret, tree[s++]);
			if(e%2 == 0) ret = max(ret, tree[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = max(ret, tree[s]);
		return ret;
	}
}seg;

int main(){
	scanf("%d %d",&n,&m);
	seg.init(n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		bit.add(i, a[i]);
		seg.add(i, a[i]);
	}
	while(m--){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int l, r;
			scanf("%d %d",&l,&r);
			printf("%lld\n",bit.query(r) - bit.query(l-1));
		}
		if(t == 2){
			int l, r, x;
			scanf("%d %d %d",&l,&r,&x);
			while(1){
				pi t = seg.query(l, r);
				if(t.first < x) break;
				bit.add(t.second, -t.first);
				bit.add(t.second, t.first % x);
				seg.add(t.second, t.first % x);
				a[t.second] = t.first % x;
			}
		}
		if(t == 3){
			int k, x;
			scanf("%d %d",&k,&x);
			bit.add(k, x - a[k]);
			seg.add(k, x);
			a[k] = x;
		}
	}
}