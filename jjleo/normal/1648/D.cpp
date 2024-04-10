#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long LL;

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1) 

struct Seg{
	LL sum[maxn << 2];
	
	void modify(int x, int l, int r, int pos, LL d){
		sum[x] = max(sum[x], d);
		if(l == r) return;
		int mid = l + r >> 1;
		if(mid >= pos) modify(ls(x), l, mid, pos, d);
		else modify(rs(x), mid + 1, r, pos, d);
	}
	
	LL query(int x, int l, int r, int ll, int rr){
		if(ll <= l && r <= rr) return sum[x];
		int mid = l + r >> 1;
		LL ans = -1e18;
		if(mid >= ll) ans = max(ans, query(ls(x), l, mid, ll, rr));
		if(mid < rr) ans = max(ans, query(rs(x), mid + 1, r, ll, rr));
		return ans;
	}
	
	void build(int x, int l, int r){
		sum[x] = -1e18;
		if(l == r) return;
		int mid = l + r >> 1;
		build(ls(x), l, mid), build(rs(x), mid + 1, r);
	}
}T[2];

struct Node{
	LL a, b, sum;
}t[maxn << 2];

inline Node up(Node l, Node r){
	Node x;
	x.a = max(l.a, r.a);
	x.b = max(l.b, r.b);
	x.sum = max({l.sum, r.sum, l.a + r.b});
	return x;
}

Node query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x];
	int mid = l + r >> 1;
	if(mid >= rr) return query(ls(x), l, mid, ll, rr);
	if(mid < ll) return query(rs(x), mid + 1, r, ll, rr);
	return up(query(ls(x), l, mid, ll, rr), query(rs(x), mid + 1, r, ll ,rr));
}

LL A[maxn], B[maxn];

void build(int x, int l, int r){
	if(l == r){
		t[x] = {A[l], B[l], A[l] + B[l]};
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	t[x] = up(t[ls(x)], t[rs(x)]); 
}

int n, m;
LL a[3][maxn]; 
tuple<int, int, int> b[maxn];
LL f[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < 3;i++) for(int j = 1;j <= n;j++) scanf("%lld", &a[i][j]), a[i][j] += a[i][j - 1];
	for(int i = 1;i <= m;i++) scanf("%d%d%d", &get<1>(b[i]), &get<0>(b[i]), &get<2>(b[i]));
	sort(b + 1, b + 1 + m);
	T[0].build(1, 1, n), T[1].build(1, 1, n);
	for(int i = 1;i <= n;i++) T[0].modify(1, 1, n, i, a[0][i] - a[1][i - 1]), f[i] = -1e18;
	for(int i = 1;i <= m;i++){
		int l = get<1>(b[i]), r = get<0>(b[i]), k = get<2>(b[i]);
		LL x = max(T[0].query(1, 1, n, l, r), T[1].query(1, 1, n, max(1, l - 1), r)) + a[1][r] - k;
		f[r] = max(f[r], x);
		T[1].modify(1, 1, n, r, f[r] - a[1][r]);
	}
	LL ans = -1e18;
	for(int i = 1;i <= n;i++){
		A[i] = f[i] - a[1][i];
		B[i] = a[1][i] + a[2][n] - a[2][i - 1];
	}
	build(1, 1, n);
	for(int i = 1;i <= m;i++){
		int l = get<1>(b[i]), r = get<0>(b[i]), k = get<2>(b[i]);
		ans = max(ans, query(1, 1, n, max(1, l - 1), r).sum - k);
	}
	for(int i = 1;i <= n;i++) A[i] = a[0][i] - a[1][i - 1];
	build(1, 1, n);
	for(int i = 1;i <= m;i++){
		int l = get<1>(b[i]), r = get<0>(b[i]), k = get<2>(b[i]);
		ans = max(ans, query(1, 1, n, l, r).sum - k);
	}
	printf("%lld", ans);
}