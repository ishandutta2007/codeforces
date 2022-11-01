#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long LL;

struct Node{
	LL sum, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
} 

inline void add(int x, int l, int r, LL y){
	t[x].sum += y * (r - l + 1);
	t[x].tag += y;
}

inline void down(int x, int l, int r){
	if(t[x].tag){
		int mid = l + r >> 1;
		add(ls(x), l, mid, t[x].tag), add(rs(x), mid + 1, r, t[x].tag);
		t[x].tag = 0;
	}
}

void modify(int x, int l, int r, int ll, int rr, LL d){
	if(ll <= l && r <= rr){
		add(x, l, r, d);
		return;
	}
	down(x, l, r);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

LL query(int x, int l, int r, int pos){
	if(l == r) return t[x].sum;
	down(x, l, r);
	int mid = l + r >> 1;
	if(mid >= pos) return query(ls(x), l, mid, pos);
	else return query(rs(x), mid + 1, r, pos); 
}

int n, k;
int ans = 1e9, m = 1e6;
int a[maxn];

int Query(int k){
	int l = 0, r = m, x = 1, mid;
	while(l < r){
		down(x, l, r);
		int mid = l + r >> 1;
		if(t[ls(x)].sum >= k) x = ls(x), r = mid;
		else k -= t[ls(x)].sum, x = rs(x), l = mid + 1;
	}
	return l; 
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n, greater<int>());
	int x = 0;
	modify(1, 0, m, 0, 0, 1);
	for(int i = 1;i <= n;i++){
		modify(1, 0, m, x, x, -1);
		modify(1, 0, m, x + 2, x + 2 + (a[i] - 1) / 2 - 1, 1);
		modify(1, 0, m, x + 2, x + 2 + (a[i] - 1 + 1) / 2 - 1, 1);
		while(!query(1, 0, m, x)) x++;//debug: 
		if(t[1].sum >= k) ans = min(ans, Query(k));
	}
	printf("%d", ans == 1e9 ? -1 : ans);
}