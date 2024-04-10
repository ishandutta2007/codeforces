#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m, L;
int a[20][20], f[1<<20], x[20], s[20], g[20], h[20][20], c[20][20];
char t[20][25];

int main() {
	scanf("%d%d", &n, &m); L=1<<n;
	FO(i,0,n) scanf("%s", t[i]);
	FO(i,0,n) FO(j,0,m) scanf("%d",a[i]+j);
	FO(j,0,m) {
		FO(i,0,20) x[i]=s[i]=g[i]=0;
		FO(i,0,n) {
			int l=t[i][j]-'a';
			x[l] = max(x[l],a[i][j]);
			s[l] += a[i][j];
			g[l] |= 1<<i;
		}
		FO(i,0,n) {
			int l=t[i][j]-'a';
			h[i][j] = g[l]; c[i][j] = s[l]-x[l];
		}
	}
	FO(l,1,L) f[l]=1e9;
	FO(l,0,L-1) {
		int i = __builtin_ctz(~l);
		FO(j,0,m) {
			f[l|h[i][j]] = min(f[l|h[i][j]],f[l]+c[i][j]);
			f[l|1<<i] = min(f[l|1<<i],f[l]+a[i][j]);
		}
	}
	printf("%d\n", f[L-1]);
}