#include <stdio.h>
#include <algorithm>
#include <queue>
#include <math.h>
#include <map>
#include <deque>
#include <string>
#include <string.h>
#include <memory.h>
#define N 2222
int t[N],c[N],n;
long long f[N][N+N];


int main(void) {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&t[i],&c[i]);
	}
	memset(f,63,sizeof(f));
	
	f[1][n] = 0;
	for (int i=1;i<=n;i++) 
		for (int j=0;j<=n+n;j++) {
			int nj = j + t[i];
			if (nj > n+n) nj = n+n;
			if (j) f[i+1][j-1] = std::min(f[i+1][j-1],f[i][j]);
			f[i+1][nj] = std::min(f[i+1][nj],f[i][j] + (long long) c[i]);
		}
	
	long long ans = f[n+1][n];
	for (int i=1;i<=n;i++) ans = std::min(ans,f[n+1][n+i]);
	printf("%I64d\n",ans);
	
	return 0;
}