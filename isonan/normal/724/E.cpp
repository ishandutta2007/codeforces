#include <cstdio>
#include <cstring>
#include <algorithm>

long long f[2][10001];
int n,p[10001],s[10001],c;
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	int u=1;
	for(int i=0;i<2;i++)
		for(int j=0;j<=n;j++)
			f[i][j]=1e18;
	f[u][0]=0;
	for(int i=1;i<=n;i++){
		u^=1;
		f[u][0]=f[u^1][0]+p[i];
		for(int j=1;j<=i;j++)
			f[u][j]=std::min(f[u^1][j]+1ll*c*j+p[i],f[u^1][j-1]+s[i]);
	}
	long long ans=1e18;
	for(int i=0;i<=n;i++)ans=std::min(ans,f[u][i]);
	printf("%lld\n",ans);
}