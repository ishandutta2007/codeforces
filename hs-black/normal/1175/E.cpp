#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 505000;
int l, r;
int n, m;
int read(void) {
	int x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return x;
}

int f[N][22], R;
int main() {
	n = read(), m = read();
	for (int i = 1;i <= n; i++) {
		l = read(), r = read();
		f[l][0] = max(f[l][0], r), R = max(R, r);
	}
	for (int i = 1;i <= R; i++) 
		f[i][0] = max(f[i][0], f[i-1][0]);
	for (int i = R;i >= 0; i--) 
		for (int j = 1;j <= 20; j++)
			f[i][j] = f[f[i][j-1]][j-1];
	while (m--) {
		int x = read(), y = read();
		int ans = 0; 
		for (int i = 20;i >= 0; i--) 
			if (f[x][i] < y)  {
				ans += 1 << i;
				x = f[x][i];
			}
		if (f[x][0] >= y) printf ("%d\n", ans + 1);
		else printf ("-1\n");
	}
	return 0;
}