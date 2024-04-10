#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int h, w, a[405][405], r;
int f[405][405], g[405][405];

int t[160005], T;
int c[160005];
int n;

void clear() {
	n = 0;
	T++;
}

void u(int i, int d) {
	if (t[i] != T) {
		t[i] = T;
		c[i] = 0;
	}
	n -= c[i]>1;
	c[i] += d;
	n += c[i]>1;
}

bool good(int y, int x1, int x2) {
	return x2<x1 || !n && f[y][x1] >= x2 && f[y+1][x1] >= x2;
}

int main() {
	scanf("%d%d", &h, &w);
	FO(y,0,h) FO(x,0,w) scanf("%d", a[y]+x);
	FO(y,0,h+1) FO(x,0,w) f[y][x]=w-1;
	FO(dy,1,h+1) {
		FO(y,0,h-dy+1) {
			clear();
			int x2 = -1;
			FO(x,0,w) {
				while (good(y,x,x2)) {
					x2++;
					u(a[y][x2],1);
					if (dy>1) u(a[y+dy-1][x2],1);
				}
				g[y][x] = x2-1;
				r = max(r, dy*(x2-x));
				u(a[y][x],-1);
				if (dy>1) u(a[y+dy-1][x],-1);
			}
		}
		memcpy(f, g, sizeof f);
	}
	printf("%d\n", r);
}