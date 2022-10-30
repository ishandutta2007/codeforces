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
	t[x].sum = max(t[ls(x)].sum, t[rs(x)].sum); 
}

inline void add(int x, int y){
	t[x].sum += y, t[x].pl += y; 
}

inline void down(int x){
	if(t[x].pl){
		add(ls(x), t[x].pl), add(rs(x), t[x].pl), t[x].pl = 0;
	}
}

inline void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll > rr) return;//debug: 
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

int n, m, p;
int x, y;
LL ans = -1e18;
struct A{
	int x, y, z;
}a[maxn], b[maxn], c[maxn];

void build(int x, int l, int r){
	if(l == r){
		t[x].sum = -b[l].y;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r), up(x);
}

inline bool cmp(A a, A b){
	return a.x < b.x;
}

int main(){
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 1;i <= n;i++) scanf("%d%d", &a[i].x, &a[i].y);
	for(int i = 1;i <= m;i++) scanf("%d%d", &b[i].x, &b[i].y);
	for(int i = 1;i <= p;i++) scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].z);
	sort(a + 1, a + 1 + n, cmp), sort(b + 1, b + 1 + m, cmp), sort(c + 1, c + 1 + p, cmp);
	build(1, 1, m);
	for(int i = 1;i <= n;i++){
		y = lower_bound(c + 1, c + 1 + p, a[i], cmp) - (c + 1);//debug:lowerbound   
		while(x < y) ++x, modify(1, 1, m, upper_bound(b + 1, b + 1 + m, (A){c[x].y, 0, 0}, cmp) - b, m, c[x].z);
		ans = max(ans, t[1].sum - a[i].y);
	}
	printf("%lld", ans);
}