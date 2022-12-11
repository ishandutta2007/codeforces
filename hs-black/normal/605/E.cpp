#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 1005;
double p[N][N], pr[N], s[N], d[N];
int vis[N], n;
int main() {
	read(n);
	for (int i = 1;i <= n; s[i] = pr[i] = 1, i++)
		for (int j = 1;j <= n; j++) {
			int x; read(x); p[i][j] = x / 100.0;
		}
	
	int x = n; d[0] = 1e9;
	for (int i = 1;i <= n; i++) {
		if (x == 1) return printf ("%.8lf\n", d[1]), 0;
		vis[x] = 1;
		for (int j = 1;j <= n; j++) {
			if (vis[j]) continue;
			s[j] += d[x] * p[j][x] * pr[j];
			pr[j] *= (1 - p[j][x]); d[j] = s[j] / (1 - pr[j]);
		}
		x = 0;
		for (int j = 1;j <= n; j++) 
			if (!vis[j] && d[j] < d[x]) x = j;
	}
	puts("kick your ass back here!"); 
	return 0;
}