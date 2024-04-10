#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

struct SegmentTree{
	struct Node{
		int sum, tag;
	}t[maxn << 2];
	
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	
	inline void up(int x){
		t[x].sum = max(t[ls(x)].sum, t[rs(x)].sum);
	} 
	
	inline void add(int x, int y){
		t[x].sum += y, t[x].tag += y;
	}
	
	inline void down(int x){
		if(t[x].tag){
			add(ls(x), t[x].tag);
			add(rs(x), t[x].tag);
			t[x].tag = 0; 
		}
	}
	
	void modify(int x, int l, int r, int ll, int rr, int d){
		if(ll > rr) return;
		if(ll <= l && r <= rr){
			add(x, d);
			return;
		}
		down(x);
		int mid = l + r >> 1;
		if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
		if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
		up(x);
	}
	
	int query(int x, int l, int r, int ll, int rr){
		if(ll > rr) return 0;
		if(ll <= l && r <= rr) return t[x].sum;
		down(x);
		int mid = l + r >> 1, ans = 0;
		if(mid >= ll) ans = max(ans, query(ls(x), l, mid, ll, rr));
		if(mid < rr) ans = max(ans, query(rs(x), mid + 1, r, ll, rr));
		return ans;
	}
}tree[2];

	

struct X{
	int l, r, t;
}a[maxn];

inline bool cmp(X x, X y){
	return x.l ^ y.l ? x.l < y.l : x.r < y.r;
}

int n;
int b[maxn], n0;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].t);
		b[++n0] = a[i].l, b[++n0] = a[i].r;
		a[i].t--;
	}
	sort(a + 1, a + 1 + n, cmp);
	sort(b + 1, b + 1 + n0);
	n0 = unique(b + 1, b + 1 + n0) - (b + 1);
	for(int i = 1;i <= n;i++){
		int l = lower_bound(b + 1, b + 1 + n0, a[i].l) - b, r = lower_bound(b + 1, b + 1 + n0, a[i].r) - b;
		int val = tree[a[i].t ^ 1].query(1, 1, n0, 1, l - 1);
		val = max(val, tree[a[i].t].query(1, 1, n0, 1, r));
		//printf("%d %d %d %d--\n", a[i].l, a[i].r, a[i].t, val);
		tree[a[i].t].modify(1, 1, n0, r, n0, 1);
		int x = tree[a[i].t].query(1, 1, n0, r, r);
		tree[a[i].t].modify(1, 1, n0, r, r, max(x, val + 1) - x);
	}
	printf("%d", max(tree[0].t[1].sum, tree[1].t[1].sum));
}