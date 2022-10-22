#include <bits/stdc++.h>
using namespace std;
int x[4], y[4], xx[4], yy[4];
int q[500][500];
int lx = 0x3f3f3f3f, ly = 0x3f3f3f3f, hx, hy;
int main() {
	int i,j;
	for (i = 0; i < 4; i++)scanf("%d%d", x + i, y + i);
	for (i = 0; i < 4; i++)scanf("%d%d", xx + i, yy + i);
	for (i = 0; i < 4; i++) {
		x[i] += 200, xx[i] += 200, y[i] += 200, yy[i] += 200;
		lx = min(lx, x[i]);
		ly = min(ly, y[i]);
		hx = max(hx, x[i]);
		hy = max(hy, y[i]);
	}
	for (i = lx; i <= hx; i++) {
		for (j = ly; j <= hy; j++) {
			q[i][j]++;
		}
	}
	lx = 0x3f3f3f3f, ly = 0x3f3f3f3f,hx=0,hy=0;
	for (i = 0; i < 4; i++) {
		lx = min(lx, xx[i]);
		ly = min(ly, yy[i]);
		hx = max(hx, xx[i]);
		hy = max(hy, yy[i]);
	}
	int mx = (lx + hx) / 2, my = (ly + hy) / 2;
	for (i = 0; lx + i <= mx; i++) {
		for (j = my - i; j <= my + i; j++) {
			q[lx+i][j]++;
		}
	}
	for (i = 0; hx- i > mx; i++) {
		for (j = my - i; j <= my + i; j++) {
			q[hx-i][j]++;
		}
	}
	bool sect = 0;
	for (i = 0; i < 500; i++)for (j = 0; j < 500; j++)if (q[i][j] == 2)sect = 1;
	if (sect)printf("YES");
	else printf("NO");
	getchar(); getchar();
}