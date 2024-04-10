// Hydro submission #62c673afc3a9fda5622ac222@1657172912810
#include <bits/stdc++.h>
using namespace std;
const int N=401;
int n,m,r[N],c[N],a[N][N];
bool check() {
	int flag=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			if (a[i][j]^r[i]^c[j]) flag=1;
			if (flag && !(a[i][j]^r[i]^c[j])) return 0;
		}
	puts("YES");
	for (int i=1; i<=n; i++) putchar(r[i]+'0'); puts("");
	for (int i=1; i<=m; i++) putchar(c[i]+'0'); puts("");
	return 1;
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d",&a[i][j]);
	for (int i=1; i<=m; i++) c[i]=a[1][i];
	for (int x=1; x<=n; x++) {
		for (int i=1; i<=n; i++) r[i]=(a[i][1]^c[1]^(i>x));
		if (check()) return 0;
	}
	for (int i=1; i<=m; i++) c[i]=(a[n][i]^1);
	for (int x=1; x<=n; x++) {
		for (int i=1; i<=n; i++) r[i]=(a[i][1]^c[1]^(i>=x));
		if (check()) return 0;
	}
	puts("NO");
	return 0;
}