#include <bits/stdc++.h>
#define FO(i,a,b) for (int i = (a); i < (b); i++)
int c[2005][2005],k,r=1,p,x;
int main() {
	FO(i,0,2005) c[i][0] = 1;
	FO(i,1,2005) FO(j,1,i+1) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % 1000000007;
	scanf("%d", &k);
	FO(i,0,k) {
		scanf("%d", &x);
		r = r * 1ll * c[p+x-1][p] % 1000000007;
		p += x;
	}
	printf("%d\n", r);
}