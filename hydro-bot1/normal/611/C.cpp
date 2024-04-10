// Hydro submission #6135dabeed161c66c7bdd343@1630919358829
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 510;
int h, w, q, sh[N][N], sw[N][N];
char a[N][N];

long long read() {
	char ch;
	long long ans = 0, f = 1;
	ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans * f;
}

char cread() {
	char ch;
	ch = getchar();
	while (ch != '.' && ch != '#') 
		ch = getchar();
	return ch;
}

int main() {
	h = read(); w = read();
	for (int i = 1; i <= h; i++) 
		for (int j = 1; j <= w; j++) 
			a[i][j] = cread();
	for (int i = 1; i <= h; i++) 
		for (int j = 1; j <= w; j++) {
			sh[i][j] = sh[i - 1][j] + sh[i][j - 1] - sh[i - 1][j - 1] + (a[i][j] == '.' && a[i - 1][j] == '.');
			sw[i][j] = sw[i - 1][j] + sw[i][j - 1] - sw[i - 1][j - 1] + (a[i][j] == '.' && a[i][j - 1] == '.');
			//printf("%d %d %d %d\n", i, j, sh[i][j], sw[i][j]);
		}
	q = read();
	for (int i = 1; i <= q; i++) {
		int r1 = read(), c1 = read(), r2 = read(), c2 = read();
		printf("%d\n", sh[r2][c2] - sh[r1][c2] - sh[r2][c1 - 1] + sh[r1][c1 - 1] + sw[r2][c2] - sw[r1 - 1][c2] - sw[r2][c1] + sw[r1 - 1][c1]);
	}
	return 0;
}