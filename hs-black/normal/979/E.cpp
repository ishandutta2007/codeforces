
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int P  = 1e9 + 7;
const int N = 2005;
int a[N], n, p;
ll mi[N], f[N][2][2][2]; // i , odd, oddw, oddb
void Add(ll &x, ll y) { x += y, x >= P && (x -= P); }
int main() {
	read(n), read(p); mi[0] = 1;
	for (int i = 1;i <= n; i++) 
		mi[i] = mi[i-1] * 2 % P, read(a[i]);
	f[0][0][0][0] = 1;
	for (int i = 1;i <= n; i++) {
		for (int j = 0;j <= 1; j++) {
			for (int k = 0;k <= 1; k++) { 
				for (int t = 0;t <= 1; t++) {
					int tp = f[i-1][j][k][t];
					if (!tp) continue;
					if (a[i] != 0) {
						if (t) {
							Add(f[i][j][k][t], mi[i-2] * tp % P);
							Add(f[i][j^1][k|1][t], mi[i-2] * tp % P);
						}
						else Add(f[i][j^1][k|1][t], mi[i-1] * tp % P);
					}
					if (a[i] != 1) {
						if (k) {
							Add(f[i][j][k][t], mi[i-2] * tp % P);
							Add(f[i][j^1][k][t|1], mi[i-2] * tp % P);
						}
						else Add(f[i][j^1][k][t|1], mi[i-1] * tp % P);
					}
				}
			}
		}
	}
	write((f[n][p][0][0] + f[n][p][0][1] + f[n][p][1][0] + f[n][p][1][1]) % P);
	return 0;
}