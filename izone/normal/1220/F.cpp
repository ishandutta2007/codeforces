#include<cstdio>
#include<algorithm>
#define SZ 524288
using namespace std;
int n, w[601000], Left[601000], Right[601000], st[601000], top, LD[601000], RD[601000];
struct SegTree {
	int Mx[SZ + SZ], K[SZ+SZ];
	void Add2(int nd, int x) {
		Mx[nd] += x;
		K[nd] += x;
	}
	void Spread(int nd) {
		Add2(nd * 2, K[nd]);
		Add2(nd * 2 + 1, K[nd]);
		K[nd] = 0;
	}
	void UDT(int nd) {
		Mx[nd] = max(Mx[nd * 2], Mx[nd * 2 + 1]);
	}
	void Add(int nd, int b, int e, int s, int l, int c) {
		if (s > l)return;
		if (s <= b && e <= l) {
			Add2(nd, c);
			return;
		}
		int m = (b + e) >> 1;
		Spread(nd);
		if (s <= m)Add(nd * 2, b, m, s, l, c);
		if (l > m)Add(nd * 2 + 1, m + 1, e, s, l, c);
		UDT(nd);
	}
	int Get(int nd, int b, int e, int x) {
		if (b == e)return Mx[nd];
		int m = (b + e) >> 1;
		Spread(nd);
		if (x <= m)return Get(nd * 2, b, m, x);
		else return Get(nd * 2 + 1, m + 1, e, x);
	}
}IT;

int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 1; i <= n + n; i++)w[n + i] = w[i];

	for (i = 1; i <= 2 * n; i++) {
		while (top && w[st[top]] >= w[i]) {
			Right[st[top]] = i;
			top--;
		}
		st[++top] = i;
	}
	top = 0;

	for (i = 2 * n; i >= 1; i--) {
		while (top && w[st[top]] > w[i]) {
			Left[st[top]] = i;
			top--;
		}
		st[++top] = i;
	}
	for (i = 1; i <= n+n; i++) {
		LD[i] = LD[Left[i]] + 1;
	}
	for (i = n; i >= 1; i--) {
		RD[i] = RD[Right[i]] + 1;
	}
	for (i = 1; i <= n; i++) {
		IT.Add(1, 1, n + n, i, i, LD[i] + RD[i] - 1);
	}
	int res = 1e9, pv = -1;
	for (i = 1; i <= n; i++) {
		if (res > IT.Mx[1]) {
			res = IT.Mx[1];
			pv = i - 1;
		}
		int t = IT.Get(1, 1, n + n, i);
		IT.Add(1, 1, n + n, i, i, -t);
		IT.Add(1, 1, n + n, i+1, Right[i] - 1, -1);
		IT.Add(1, 1, n + n, max(Left[i + n],i) + 1, i + n - 1, 1);
		IT.Add(1, 1, n + n, i + n, i + n, LD[i+n]);
	}
	printf("%d %d\n", res, pv);
}