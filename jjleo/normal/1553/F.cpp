#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long LL;

const int m = 300000;

struct Node{
	LL sum, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
}

inline void add(int x, LL y, int l, int r){
	t[x].sum += y * (r - l + 1), t[x].tag += y;
}

inline void down(int x, int l, int r){
	if(!t[x].tag) return;
	int mid = l + r >> 1;
	add(ls(x), t[x].tag, l, mid), add(rs(x), t[x].tag, mid + 1, r);
	t[x].tag = 0;
}

void modify(int x, int l, int r, int ll, int rr, LL d){
	if(ll <= l && r <= rr){
		add(x, d, l, r);
		return;
	}
	int mid = l + r >> 1;
	down(x, l, r);
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

LL query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].sum;
	int mid = l + r >> 1;
	down(x, l, r);
	LL sum = 0;
	if(mid >= ll) sum += query(ls(x), l, mid, ll, rr);
	if(mid < rr) sum += query(rs(x), mid + 1, r, ll, rr);
	return sum;
}

struct BIT{
	LL B[maxn];

	inline void add(int x, LL y){
		for(;x <= m;x += x & -x) B[x] += y;
	}
	
	inline LL query(int x){
		if(x <= 0) return 0;
		LL sum = 0;
		for(;x;x -= x & -x) sum += B[x];
		return sum;
	}
}A, B;

int n;
int x;

int main(){
	scanf("%d", &n);
	LL ans = 0;
	while(n--){
		scanf("%d", &x);
		for(int i = 0;i <= m;i += x){
			int r = min(m, i + x - 1);
			ans += A.query(r) - A.query(i - 1) - (B.query(r) - B.query(i - 1)) * i;
		}
		ans += query(1, 0, m, 0, x);
		A.add(x, x), B.add(x, 1);
		for(int i = 0;i <= m;i += x){
			int r = min(m, i + x - 1);
			if(i + 1 <= r) modify(1, 0, m, i + 1, r, 1);
			if(r < m) modify(1, 0, m, r + 1, r + 1, -(x - 1));
		}
		printf("%lld ", ans);
	}
}