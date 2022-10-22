#include <bits/stdc++.h>
#define mid (l+r)/2
using namespace std;
typedef long long ll;
bitset<10001> v[40000];
int n;
void u(int a, int b,int c,int l=0,int r=n-1,int x=1) {
	if (a == l && b == r) {
		if (l == r)v[x] |= v[x] << c;else  v[x][c] = 1; return;
	}
	else if (a > mid)u(a, b, c, mid+1, r,(x<<1)|1);
	else if (b <= mid)u(a, b, c, l, mid, x << 1);
	else u(a, mid, c, l, mid, x << 1), u(mid + 1, b, c, mid + 1, r, (x << 1) | 1);
}
void idk(int l = 0, int r = n - 1, int x = 1) {
	if (l == r)return;
	idk(l, mid, x << 1);
	idk(mid + 1, r, (x << 1) | 1);
	bitset<10001> th =  v[2 * x + 1]|v[2*x];
	for (int i = 1; i <= n; i++) { if (v[x][i])th |=( th << i); }
	v[x] = th;
}
int main() {
	int  q,i,a,b,c;
	scanf("%d%d", &n, &q);
	for (i = 0; i < 40000; i++)v[i][0] = 1;
	for (i = 0; i < q; i++) {
		scanf("%d%d%d", &a, &b, &c);
		u(a - 1, b - 1, c);
	}
	idk();
	bitset<10001> limiter;
	for (i = 1; i <= n; i++)limiter[i] = 1;
	v[1] &= limiter;
	printf("%d\n", v[1].count());
	for (i = 1; i <= n; i++)if (v[1][i])printf("%d ", i);
	getchar(); getchar();
}