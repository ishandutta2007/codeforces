#include <bits/stdc++.h>
#define FO(i,a,b) for (int i = (a); i < (b); i++)
int n; long long k, f[55];
int main() {
	scanf("%d %lld", &n, &k);
	f[0] = f[1] = 1;
	FO(i,2,55) f[i] = f[i-1] + f[i-2];
	FO(i,0,n) if (k <= f[n-i-1]) printf("%d%c", i+1, " \n"[i+1==n]);
	else printf("%d %d%c", i+2, i+1, " \n"[i+2==n]), k -= f[n-++i];
}