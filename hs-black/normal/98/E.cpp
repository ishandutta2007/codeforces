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
inline void write(F x)
{
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar('\n');
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y, 0); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 2005;
int m, n;
double f[N][N];
int main() {
	read(n), read(m); int mx = max(n, m);
	for (int i = 0;i <= mx; i++) f[i][0] = 1;
	for (int i = 1;i <= mx; i++) f[0][i] = 1.0 / (i + 1);
	for (int i = 2;i <= n + m; i++) {
		for (int j = 1;j < i; j++) {
			if (i - j < 1) continue;
			int x = j, y = i - j;
			double inv = 1.0 / (y + 1);
			double c = inv * y * (1 - f[y-1][x]), b = 1.0 - f[y][x-1];
			double d = c + inv;
			double p = (1.0 - b) / (1 - c + d - b);
			f[x][y] = p * c + (1 - p);
		}
	}
	printf ("%.9lf %.9lf\n", f[n][m], 1 - f[n][m]);
	return 0;
}

/*

1 2

*/