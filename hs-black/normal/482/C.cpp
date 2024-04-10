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

const int N = 2005000;
inline ll to(int x) { return 1ll << x; }

int all, m, n;
char s[60][30];
ll t[N], siz[N], f[N];
double g[N];

int main() {
	read(n);
	for (int i = 1;i <= n; i++) scanf ("%s", s[i] + 1);
	m = strlen(s[1] + 1), all = to(m) - 1;
	for (int i = 1;i <= n; i++) {
		for (int j = 1;j < i; j++) {
			int S = 0;
			for (int k = 1;k <= m; k++)
				if (s[i][k] == s[j][k]) S |= to(k-1);
			t[S] |= to(j-1) | to(i-1);
		}
	}
	for (int i = 1;i <= all; i++) siz[i] = siz[i>>1] + (i & 1);
	
	for (int i = all;i >= 1; i--) 
		for (int j = 0;j < m; j++)
			if (i & to(j)) t[i^to(j)] |= t[i];
	for (int i = 0;i <= all; i++) 
		for (int j = 0;j < n; j++) 
			if (t[i] & to(j)) f[i]++;
	
	for (int i = all - 1;i >= 0; i--) {
		if (!f[i]) continue;
		double sum = 0;
		for (int j = 1;j <= m; j++)
			if (!(to(j-1) & i)) sum += g[i | to(j-1)] * f[i | to(j-1)] / f[i];
		g[i] = (sum / (m - siz[i]) + 1);
	}
	printf ("%.12lf\n", g[0]);
	return 0;
}