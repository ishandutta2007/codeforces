#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define int long long

int n,k;
long long ans=1e18;
int len[81][81],col[81],f[81][101];
signed main(){
	scanf("%lld%lld",&n,&k);
	srand(19260817);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lld",&len[i][j]);
	for(int i=1;i<6000;i++){
		for(int j=1;j<=n;j++)col[j]=rand()%2;
		for(int j=0;j<=k;j++)
			for(int l=1;l<=n;l++)
				f[l][j]=1e15;
		f[1][0]=0;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				for(int l=1;l<=n;l++)
					if(col[l]!=col[j])f[l][i]=std::min(f[l][i],f[j][i-1]+len[j][l]);
		ans=std::min(ans,f[1][k]);
	}
	printf("%lld\n",ans);
}