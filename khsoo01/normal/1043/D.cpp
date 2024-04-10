#include<bits/stdc++.h>
using namespace std;

const int N = 100005, M = 12;

int n, m, a[M][N], b[M][N], dt[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			scanf("%d",&a[i][j]);
			b[i][a[i][j]] = j;
		}
	}
	dt[a[1][n]] = 1;
	long long ans = 1;
	for(int i=n-1;i>=1;i--) {
		int I = a[1][i], J = a[1][i+1];
		bool F = true;
		for(int j=1;j<=m;j++) {
			if(a[j][b[j][I]+1] != J) {
				F = false;
				break;
			}
		}
		if(F) dt[I] = dt[J] + 1;
		else dt[I] = 1;
		ans += dt[I];
	}
	printf("%lld\n",ans);
}