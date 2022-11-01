#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long LL;

namespace BIT{
	LL a[maxn], b[maxn];
	
	inline void add(int x, int y){
		for(LL xy = 1ll * x * y;x < maxn;x += x & -x) a[x] += y, b[x] += xy;
	}
	
	inline LL query(int x){
		LL sum = 0;
		for(int X = x + 1;x;x -= x & -x) sum += X * a[x] - b[x];
		return sum;
	}
}

namespace Seg{
	struct Node{
		int mx, cnt, sx;
	}t[maxn << 2];
	
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	
	inline void up(int x){
		if(t[ls(x)].mx == t[rs(x)].mx){
			t[x].mx = t[ls(x)].mx, t[x].sx = max(t[ls(x)].sx, t[rs(x)].sx);
			t[x].cnt = t[ls(x)].cnt + t[rs(x)].cnt;
		}else if(t[ls(x)].mx > t[rs(x)].mx){
			t[x].mx = t[ls(x)].mx, t[x].sx = max(t[ls(x)].sx, t[rs(x)].mx);
			t[x].cnt = t[ls(x)].cnt;
		}else{
			t[x].mx = t[rs(x)].mx, t[x].sx = max(t[ls(x)].mx, t[rs(x)].sx);
			t[x].cnt = t[rs(x)].cnt;
		}
	}
	
	inline void cover(int x, int d){
		//BIT::add(t[x].mx + 1, t[x].cnt);
		t[x].mx = d;
		//BIT::add(t[x].mx + 1, -t[x].cnt);
	}
	
	inline void down(int x){
		if(t[ls(x)].mx > t[x].mx) cover(ls(x), t[x].mx);
		if(t[rs(x)].mx > t[x].mx) cover(rs(x), t[x].mx);
	}
	
	void modify(int x, int l, int r, int ll, int rr, int d){
		if(t[x].mx <= d) return;
		if(l == r || ll <= l && r <= rr && d > t[x].sx){
			BIT::add(t[x].mx + 1, t[x].cnt);
			cover(x, d);
			BIT::add(t[x].mx + 1, -t[x].cnt);
			return;
		}
		down(x);
		int mid = l + r >> 1;
		if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
		if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
		up(x);
	}
	
	void modify(int x, int l, int r, int pos, int d){
		if(l == r){
			BIT::add(t[x].mx + 1, 1);
			t[x].mx = d;
			BIT::add(t[x].mx + 1, -1);
			return;
		}
		int mid = l + r >> 1;
		down(x);
		if(mid >= pos) modify(ls(x), l, mid, pos, d);
		else modify(rs(x), mid + 1, r, pos, d);
		up(x); 
	}
	
	void build(int x, int l, int r){
		if(l == r){
			t[x].mx = l, t[x].sx = -1e9, t[x].cnt = 1;
			return;
		}
		int mid = l + r >> 1;
		build(ls(x), l, mid), build(rs(x), mid + 1, r);
		up(x); 
	}
}

int n, q;
int opt, x, y;

int main(){
	scanf("%d%d", &n, &q);
	BIT::add(1, 1);
	Seg::build(1, 1, n);
	while(q--){
		scanf("%d%d%d", &opt, &x, &y);
		if(opt == 1){
			if(x > 1) Seg::modify(1, 1, n, 1, x - 1, x - 1);
			Seg::modify(1, 1, n, x, y);
		}else{
			printf("%lld\n", BIT::query(y) - BIT::query(x - 1));
		}
	}
}