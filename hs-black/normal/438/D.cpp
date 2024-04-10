#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N = 100520;
int L[N<<3], R[N<<3];
#define ll long long
#define p1 p << 1 
#define p2 p << 1 | 1
ll sum[N<<2], mx[N<<2];
ll A[N], n, m;
void build(int l,int r,int p) {
	L[p] = l, R[p] = r;
	if (l == r) {
		sum[p] = mx[p] = A[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, p1);
	build(mid + 1, r, p2);
	sum[p] = sum[p1] + sum[p2];
	mx[p] = max(mx[p1], mx[p2]);
}
void change(int x,int p,ll k) {
	if (L[p] == R[p]) {
		mx[p] = sum[p] = k;
		return;
	}
	if (x <= R[p1]) change(x, p1, k);
	else change(x, p2, k);
	sum[p] = sum[p1] + sum[p2];
	mx[p] = max(mx[p1], mx[p2]);
}
ll ask(int l,int r,int p) {
	if (L[p] >= l && R[p] <= r) return sum[p];
	ll val = 0;
	if (R[p1] >= l) val += ask(l, r, p1);
	if (L[p2] <= r) val += ask(l, r, p2);
	return val;
}
void mod(int l,int r,int p,ll P) {
	if (mx[p] < P) return;
	if (L[p] == R[p]) {
		mx[p] = sum[p] = mx[p] % P;
		return;
	}
	if (l <= R[p1]) mod(l, r, p1, P);
	if (r >= L[p2]) mod(l, r, p2, P);
	sum[p] = sum[p1] + sum[p2];
	mx[p] = max(mx[p1], mx[p2]);
}
template <typename T>
void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	x *= f;
}
int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++) read(A[i]);
	build(1, n, 1);
	for (int i = 1;i <= m; i++) {
		ll op, l, r;
		read(op), read(l), read(r);
		if (op == 1) cout << ask(l, r, 1) << endl;
		else if (op == 3) change(l, 1, r);
		else {
			ll P;
			read(P);
			mod(l, r, 1, P);
		}
	}
	return 0;
}