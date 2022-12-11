#pragma GCC optimize(2)
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

const int N = 305;
char s[N];
ll n, m;
int g[N][2], nxt[N];

void KMP(void) {
	int j = nxt[1] = 0;
	for (int i = 2;i <= m; i++) {
		while (j && s[i] != s[j+1]) j = nxt[j];
		if (s[i] == s[j+1]) j++;
		nxt[i] = j;
	}
	for (int i = 0;i < m; i++) {
		int k = i, p = i;
		while (k && s[k+1] != '(') k = nxt[k];
		while (p && s[p+1] != ')') p = nxt[p];
		if (s[k+1] == '(') k++;
		if (s[p+1] == ')') p++;
		g[i][1] = k, g[i][0] = p;
	}
	g[m][0] = g[m][1] = m;
}

const int P = 1e9+7;
ll f[N][N][N];

inline void add(ll &x, ll y) {
	x += y; if (x >= P) x -= P;
}

int main() {
	read(n); int al = n << 1;
	scanf ("%s", s + 1);
	m = strlen(s + 1);
	KMP();
	f[0][0][0] = 1;
	for (int i = 0; i < al; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= m; k++) {
				ll t = f[i][j][k];
				if (j) add(f[i+1][j-1][g[k][0]], t);
				add(f[i+1][j+1][g[k][1]], t);
			}
		}
	}
	cout << f[al][0][m] << endl;
	return 0;
}