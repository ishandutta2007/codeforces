#include <bits/stdc++.h>
#define maxn 150086

using namespace std;

typedef long long LL;

struct Seg{
	struct Node{
		int mn, cnt, sn, tag, val;
		LL sum;
	}t[maxn << 2];
	
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	
	inline void up(int x){
		t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
		t[x].val = t[ls(x)].val + t[rs(x)].val;
		if(t[ls(x)].mn == t[rs(x)].mn){
			t[x].mn = t[ls(x)].mn, t[x].sn = min(t[ls(x)].sn, t[rs(x)].sn);
			t[x].cnt = t[ls(x)].cnt + t[rs(x)].cnt;
		}else if(t[ls(x)].mn < t[rs(x)].mn){
			t[x].mn = t[ls(x)].mn, t[x].sn = min(t[ls(x)].sn, t[rs(x)].mn);
			t[x].cnt = t[ls(x)].cnt;
		}else{
			t[x].mn = t[rs(x)].mn, t[x].sn = min(t[rs(x)].sn, t[ls(x)].mn);
			t[x].cnt = t[rs(x)].cnt;
		}
	}
	
	inline void cover(int x, int y){
		if(t[x].val == 0) return;
		t[x].sum += 1ll * (y - t[x].mn) * t[x].cnt;
		t[x].mn = y;
	}
	
	inline void add(int x, int y){
		if(t[x].val == 0) return;
		t[x].sum += 1ll * t[x].val * y;
		t[x].tag += y, t[x].mn += y, t[x].sn += y;
	}
	
	inline void down(int x){
		add(ls(x), t[x].tag), add(rs(x), t[x].tag), t[x].tag = 0;
		if(t[ls(x)].mn < t[x].mn) cover(ls(x), t[x].mn);
		if(t[rs(x)].mn < t[x].mn) cover(rs(x), t[x].mn);
	}
	
	void cover(int x, int l, int r, int ll, int rr, int d){
		if(t[x].mn >= d) return;
		if(l == r){
			if(t[x].val) t[x].mn = t[x].sum = d;
			return;
		}
		if(ll <= l && r <= rr && d < t[x].sn){
			cover(x, d);
			return;
		}
		int mid = l + r >> 1;
		down(x);
		if(mid >= ll) cover(ls(x), l, mid, ll, rr, d);
		if(mid < rr) cover(rs(x), mid + 1, r, ll, rr, d);
		up(x);
	}
	
	void add(int x, int l, int r, int ll, int rr, int d){
		if(ll <= l && r <= rr){
			add(x, d);
			return;
		}
		int mid = l + r >> 1;
		down(x);
		if(mid >= ll) add(ls(x), l, mid, ll, rr, d);
		if(mid < rr) add(rs(x), mid + 1, r, ll, rr, d);
		up(x);
	}
	
	void init(int x, int l, int r, int pos, int d){
		if(l == r){
			t[x].mn = t[x].sum = d, t[x].sn = 1e9, t[x].cnt = t[x].val = 1;
			return;
		}
		down(x);
		int mid = l + r >> 1;
		if(mid >= pos) init(ls(x), l, mid, pos, d);
		else init(rs(x), mid + 1, r, pos, d);
		up(x);
	}
	
	int query(int x, int l, int r, int ll, int rr){
		if(ll <= l && r <= rr) return t[x].val;
		int mid = l + r >> 1, sum = 0;
		down(x);
		if(mid >= ll) sum += query(ls(x), l, mid, ll, rr);
		if(mid < rr) sum += query(rs(x), mid + 1, r, ll, rr);
		return sum;
	}
	
	void build(int x, int l, int r){
		t[x].mn = t[x].sn = 1e9;
		if(l == r) return;
		int mid = l + r >> 1;
		build(ls(x), l, mid), build(rs(x), mid + 1, r);
	}
}t[2];

int n, x;
int a[maxn];

int main(){
	scanf("%d", &n), t[0].build(1, 1, n), t[1].build(1, 1, n);
	for(int i = 1;i <= n;i++) scanf("%d", &x), a[x] = i;
	for(int i = 1;i <= n;i++){
		x = a[i];
		t[0].init(1, 1, n, x, -(i + 1)), t[1].init(1, 1, n, x, 0);
		if(x + 1 <= n) t[0].add(1, 1, n, x + 1, n, -1), t[1].add(1, 1, n, x + 1, n, 1);
		int pos = x == 1 ? 1 : t[0].query(1, 1, n, 1, x);
		if(1 <= x - 1) t[0].cover(1, 1, n, 1, x - 1, -pos);
		if(x + 1 <= n) t[1].cover(1, 1, n, x + 1, n, pos);
		printf("%lld\n", -t[0].t[1].sum - t[1].t[1].sum - i);
	}
}