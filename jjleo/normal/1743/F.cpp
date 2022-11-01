#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

const int p = 998244353;

struct M{
	int a[2][2];
	
	void init(){
		memset(a, 0, sizeof(a));
	}
};

M mul(const M &l, const M &r){
	M x;x.init();
	for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) for(int k = 0;k < 2;k++) x.a[i][j] = (x.a[i][j] + 1ll * l.a[i][k] * r.a[k][j]) % p;
	return x;
}

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

M I, A, B;
M sum[maxn << 2];

void mul(int x, const M &y){
	sum[x] = mul(y, sum[x]);
}

void down(int x){
	mul(ls(x), sum[x]), mul(rs(x), sum[x]);
	sum[x] = I;
}

void modify(int x, int l, int r, int ll, int rr, const M &d){
	if(ll <= l && r <= rr){
		mul(x, d);
		return;
	}
	down(x);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
}

void build(int x, int l, int r){
	sum[x] = I;
	if(l == r) return;
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
}

int ans;
int L, R;

void solve(int x, int l, int r){
	if(l == r){
		if(L <= l && l <= R) ans = (ans + sum[x].a[1][1]) % p;
		else ans = (ans + sum[x].a[1][0]) % p;
		return;
	}
	down(x);
	int mid = l + r >> 1;
	solve(ls(x), l, mid), solve(rs(x), mid + 1, r);
}

int n;
const int m = 3e5;

int main(){
	I.a[0][0] = I.a[1][1] = 1;
	A.a[0][0] = 1, A.a[0][1] = 1, A.a[1][0] = 2, A.a[1][1] = 2;
	B.a[0][0] = 3, B.a[0][1] = 1, B.a[1][0] = 0, B.a[1][1] = 2;
	build(1, 0, m);
	scanf("%d", &n);
	n--, scanf("%d%d", &L, &R);
	while(n--){
		int l, r;
		scanf("%d%d", &l, &r);
		modify(1, 0, m, l, r, A);
		if(0 <= l - 1) modify(1, 0, m, 0, l - 1, B);
		if(r + 1 <= m) modify(1, 0, m, r + 1, m, B);
	}
	solve(1, 0, m);
	printf("%d", ans);
}