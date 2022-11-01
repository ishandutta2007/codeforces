#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

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

void build(int x, int l, int r){
	t[x].tag = 0;
	if(l == r){
		t[x].sum = l + l % 2 - 1e9;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int T, n;
int x, p[maxn], a[maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &x), p[x] = i, a[i] = 0;
		build(1, 1, n);
		int ans = 0, last = 0;
		for(int i = 1;i < n;i++){
			a[p[i]] = 1;
			modify(1, 1, n, p[i], p[i], 1e9);
			if(1 <= p[i] - 1) modify(1, 1, n, 1, p[i] - 1, 1);
			modify(1, 1, n, p[i], n, -1);
			while(a[last + 1]) last++, modify(1, 1, n, last, last, -1e9);
			ans = max(ans, t[1].sum);
		}
		printf("%d\n", ans);
	}
}