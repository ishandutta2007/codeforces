#include <bits/stdc++.h>
#define maxn 35086
#define maxk 55
using namespace std;

struct SegmentTree{
	struct Node{
		int sum, pl;	
	}t[maxn << 2];	
	
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	
	inline void up(int x){
		t[x].sum = max(t[ls(x)].sum, t[rs(x)].sum);
	}
	
	inline void plus(int x, int y){
		t[x].sum += y, t[x].pl += y;
	}
	
	inline void down(int x){
		if(t[x].pl){
			plus(ls(x), t[x].pl), plus(rs(x), t[x].pl);
			t[x].pl = 0;
		}
	}
	
	void modify(int x, int l, int r, int ll, int rr, int d){
		if(ll <= l && r <= rr){
			plus(x, d);
			return;
		}
		down(x);
		int mid = l + r >> 1;
		if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
		if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
		up(x);
	}
	
	int query(int x, int l, int r, int ll, int rr){
		if(ll <= l && r <= rr) return t[x].sum;
		down(x);
		int mid = l + r >> 1, sum = 0;
		if(mid >= ll) sum = max(sum, query(ls(x), l, mid, ll, rr));
		if(mid < rr) sum = max(sum, query(rs(x), mid + 1, r, ll, rr));
		return sum;
	}
}tree[maxk];

int n, k;
int a[maxn];
int x;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		for(int j = 0;j < k;j++){
			tree[j].modify(1, 0, n, a[x], i - 1, 1);
		}
		for(int j = 1;j <= k;j++){
			tree[j].modify(1, 0, n, i, i, tree[j - 1].query(1, 0, n, 0, i - 1));
		}
		a[x] = i;
	}
	printf("%d", tree[k].query(1, 0, n, n, n));
}