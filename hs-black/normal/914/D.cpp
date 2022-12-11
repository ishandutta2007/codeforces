// luogu-judger-enable-o2
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 500050;
struct node{
	int x;
	int l, r;
	#define x(i) tree[i].x
	#define l(i) tree[i].l
	#define r(i) tree[i].r
}tree[N<<3];
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
int n, a[N];

int gcd(int x,int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

#define p1 p << 1
#define p2 p << 1 | 1

void build(int p,int l,int r) {
	l(p) = l, r(p) = r;
	if (l == r) {
		x(p) = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p1, l, mid);
	build(p2, mid + 1, r);
	x(p) = gcd(x(p1), x(p2));
}

void change(int d,int x,int p) {
	if (l(p) == r(p)) {
		x(p) = x;
		return;
	}
	if (d <= r(p1)) change(d, x, p1);
	else change(d, x, p2);
	x(p) = gcd(x(p1), x(p2));
}
int cnt, l , r, x;
void check(int p) {
	if (cnt >= 2) return;
	if (l(p) >= l && r(p) <= r) {
		if (x(p) % x == 0) return;
		if (l(p) == r(p)) cnt++;
		else {
			check(p1);
			check(p2);
		}
		return;
	}
	if (r(p1) >= l) check(p1);
	if (r(p1) < r) check(p2);
}

int main() {
	n = read();
	for (int i = 1;i <= n; i++) a[i] = read();
	build(1, 1, n);
	int q = read();
	for (int i = 1;i <= q; i++) {
		int op = read();
		l = read();
		if (op == 1) {
			r = read(), x = read();
			cnt = 0;
			check(1);
			if (cnt <= 1) printf ("YES\n");
			else printf ("NO\n");
		}
		else {
			x = read();
			change(l, x, 1);
		}
	}
	return 0;
}