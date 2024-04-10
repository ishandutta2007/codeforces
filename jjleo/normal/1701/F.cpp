#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

typedef long long LL;

#define int long long

struct Node{
	LL sum;
	int siz, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
	t[x].siz = t[ls(x)].siz + t[rs(x)].siz;
} 

inline void add(int x, int y){
	t[x].sum += 1ll * t[x].siz * y;
	t[x].tag += y;
}

inline void down(int x){
	if(!t[x].tag) return;
	add(ls(x), t[x].tag), add(rs(x), t[x].tag);
	t[x].tag = 0;
}

void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr){
		add(x, d);
		return;
	}
	int mid = l + r >> 1;
	down(x);
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

void Modify(int x, int l, int r, int pos, int sum, int siz){
	if(l == r){
		t[x].sum = sum, t[x].siz = siz;
		return;
	}
	int mid = l + r >> 1;
	down(x);
	if(mid >= pos) Modify(ls(x), l, mid, pos, sum, siz);
	else Modify(rs(x), mid + 1, r, pos, sum, siz);
	up(x);
}

LL querySum(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].sum;
	int mid = l + r >> 1;
	LL ans = 0;
	down(x);
	if(mid >= ll) ans += querySum(ls(x), l, mid, ll, rr);
	if(mid < rr) ans += querySum(rs(x), mid + 1, r, ll, rr);
	return ans;
}

int querySiz(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].siz;
	int mid = l + r >> 1;
	int ans = 0;
	down(x);
	if(mid >= ll) ans += querySiz(ls(x), l, mid, ll, rr);
	if(mid < rr) ans += querySiz(rs(x), mid + 1, r, ll, rr);
	return ans;
}

int m, d;
bool vis[maxn];

signed main(){
	scanf("%lld%lld", &m, &d);
	LL ans = 0;
	const int n = 2e5;
	while(m--){
		int x;
		scanf("%lld", &x);
		if(!vis[x]){
			int siz = x > 1 ? querySiz(1, 1, n, max(1ll, x - d), max(1ll, x - 1)) : 0;
			ans += 1ll * siz * (siz - 1) / 2;
			if(x < n) ans += querySum(1, 1, n, min(n, x + 1), min(n, x + d));
			Modify(1, 1, n, x, siz, 1);
			if(x < n) modify(1, 1, n, min(n, x + 1), min(n, x + d), 1);
		}else{
			int siz = x > 1 ? querySiz(1, 1, n, max(1ll, x - d), max(1ll, x - 1)) : 0;
			ans -= 1ll * siz * (siz - 1) / 2;
			if(x < n) modify(1, 1, n, min(n, x + 1), min(n, x + d), -1);
			Modify(1, 1, n, x, 0, 0);
			if(x < n) ans -= querySum(1, 1, n, min(n, x + 1), min(n, x + d));
		}
		printf("%lld\n", ans);
		vis[x] ^= 1;
	}	
}
/*
4 5
2
4
7
10
*/