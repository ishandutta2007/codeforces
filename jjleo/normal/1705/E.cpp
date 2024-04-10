#include <bits/stdc++.h>
#define maxn 210086

using namespace std;

typedef long long LL;

int n, q;
int a[maxn], b[maxn];

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
};

inline void add(int l, int r, int x){
	BIT::add(l, x), BIT::add(r + 1, -x);
}

inline int query(int l, int r){
	return BIT::query(r) - BIT::query(l - 1);
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[a[i]]++;
	const int m = 2e5 + 1000;
	for(int i = 1;i <= m;i++) b[i + 1] += b[i] / 2, b[i] %= 2;
	for(int i = 1;i <= m;i++) add(i, i, b[i]);
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		int l = a[x], r = m, mid;
		while(l < r){
			mid = l + r >> 1;
			if(query(a[x], mid) == 0) l = mid + 1;
			else r = mid;
		}
		add(a[x], l - 1, 1), add(l, l, -1);
		a[x] = y;
		l = a[x], r = m, mid;
		while(l < r){
			mid = l + r >> 1;
			if(query(a[x], mid) == mid - a[x] + 1) l = mid + 1;
			else r = mid;
		}
		add(a[x], l - 1, -1), add(l, l, 1);
		l = 1, r = m;
		while(l < r){
			mid = (l + r >> 1) + 1;
			if(query(mid, m)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
	}
}