#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long LL;

struct Node{
	LL sum, pl;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = min(t[ls(x)].sum, t[rs(x)].sum);
} 

inline void add(int x, LL y){
	t[x].sum += y, t[x].pl += y; 
}

inline void down(int x){
	if(t[x].pl){
		add(ls(x), t[x].pl), add(rs(x), t[x].pl);
		t[x].pl = 0;
	}
}

void modify(int x, int l, int r, int ll, int rr, int d){
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

int n;
int p[maxn], a[maxn], b[maxn];
int x;
LL ans = 1e18;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &p[i]), b[p[i]] = i;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n - 1;i++) modify(1, 1, n - 1, i, n - 1, a[i]);
	ans = min(ans, t[1].sum);
	for(int i = 1;i <= n;i++){
		if(1 <= b[i] - 1) modify(1, 1, n - 1, 1, b[i] - 1, a[b[i]]);
		if(b[i] <= n - 1) modify(1, 1, n - 1, b[i], n - 1, -a[b[i]]);
		ans = min(ans, t[1].sum);
	}
	printf("%lld", ans);
}