#include <cstdio>
#define FO(i,a,b) for (int i = (a); i < (b); i++)
int n, m, b, a, d, c[505][505];
int main() {
	scanf("%d %d %d %d", &n, &m, &b, &d);
	FO(i,0,505) c[0][i] = 1;
	FO(i,0,n) {
		scanf("%d", &a);
		FO(l,1,505) FO(g,a,505) c[l][g] = (c[l][g]+c[l-1][g-a])%d;
	}
	printf("%d\n", c[m][b]);
}