#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
int n, a[500005];

int tree[1000005];

struct seg1{
	int tree[2100000], lazy[2100000];
	void init(int s, int e, int p){
		if(s == e){
			tree[p] = s;
			return;
		}
		int m = s + (e - s) / 2;
		init(s, m, 2*p);
		init(m+1, e, 2*p+1);
		tree[p] = min(tree[2*p], tree[2*p+1]);
	}
	void lazydown(int p){
		tree[2*p] += lazy[p];
		tree[2*p+1] += lazy[p];
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	int query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return 1e9;
		if(s <= ps && pe <= e) return tree[p];
		lazydown(p);
		int pm = (ps+pe)/2;
		return min(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
	}
	void upd(int s, int e, int ps, int pe, int p, int v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p] += v;
			lazy[p] += v;
			return;
		}
		lazydown(p);
		int pm = (ps+pe)/2;
		upd(s, e, ps, pm, 2*p, v);
		upd(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = min(tree[2*p], tree[2*p+1]);
	}
	int query(int s, int e){
		return query(s+500000, e+500000, 0, 1000000, 1);
	}
	void update(int x){
		upd(x+500000, 1000000, 0, 1000000, 1, -1);
	}
}seg1;

struct bit{
	int tree[1000005];
	void add(int x, int v){
		x += 500001;
		while(x <= 1000001){
			tree[x] += v;
			x += x & -x;
		}
	}
	int kth(int x){
		int pos = 0;
		for(int i=19; i>=0; i--){
			if(pos + (1 << i) <= 1000001 && tree[pos+(1<<i)] < x){
				pos += (1<<i);
				x -= tree[pos];
			}
		}
		return pos - 500000;
	}
}bit;

int main(){
	seg1.init(-500000, 500000, 1);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		bit.add(a[i], 1);
		int s = 0, e = i;
		while(s != e){
			int m = (s+e)/2;
			if(-m <= bit.kth(m+1)) e = m;
			else s = m+1;
		}
		int cur = -s - s;
		seg1.update(a[i]);
		if(s < i){
			cur = min(cur, seg1.query(bit.kth(s+1), 500000));
		}
		cur += i;
		printf("%d\n", cur);
	}
}