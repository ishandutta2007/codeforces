/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define ll long long
#define MP make_pair
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 1;
	for (; !isdigit(c); c = getchar())
		if (c == '-') f = -1;
	for (; isdigit(c); c = getchar())
		x = (x << 1) + (x << 3) + (c ^ '0');
	x *= f;
}

template <typename T>
void write(T x, char ed = '\n') {
	static short st[30], tp = 0;
	if (x < 0) putchar('-'), x = -x;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar('0' | st[tp--]);
	putchar(ed);
}

template <typename T>
void Mx(T &x, T y) { x < y && (x = y); }
template <typename T>
void Mn(T &x, T y) { x > y && (x = y); }

const int P = 1e9 + 7;
const int inv2 = (P + 1) / 2;
const int N = 55;
ll f[N][N][2];
int n, k;
int main() {
	read(n), read(k);
	f[0][0][1] = f[1][0][0] = 1;
	for (int i = 2;i <= n; i++) {
		int lim = (i - 1) / 2;
		for (int j = 0;j <= lim; j++) {
			int ls = j, rs = i - ls - 1;
			for (int tl = 0;tl <= ls; tl++) {
				for (int tr = 0;tr <= rs; tr++) {
					ll tl1 = f[ls][tl][1], tl0 = f[ls][tl][0];
					ll tr1 = f[rs][tr][1], tr0 = f[rs][tr][0];
					if (ls == rs) {
						f[i][tl + tr][0] = (f[i][tl + tr][0] + tl1 * tr1 % P * inv2) % P;
						f[i][tl + tr + 1][1] = (f[i][tl + tr + 1][1] + tl0 * tr0 % P * inv2 + tl1 * tr0) % P;
						continue;
					}
					f[i][tl + tr][0] = (f[i][tl + tr][0] + tl1 * tr1) % P;
					f[i][tl + tr + 1][1] = (f[i][tl + tr + 1][1] + tl1 * tr0 + tl0 * tr1 + tl0 * tr0) % P;
				}
			}
		}
	}
	ll fac = 1;
	for (int i = 1;i < n; i++) fac = fac * i % P;
	write((f[n][k][0] + f[n][k][1]) * fac % P);
	return 0;
}

/*

9 4

*/