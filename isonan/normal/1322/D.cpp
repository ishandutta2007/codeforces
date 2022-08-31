#include <cstdio>
#include <cstring>
#include <algorithm>

int n,m;
int l[2001],s[2001],c[4001];
int f[2030][2010];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",l+i);
	for(int i=1;i<=n;++i)scanf("%d",s+i);
	for(int i=1;i<=n+m;++i)scanf("%d",c+i);
	m+=std::min(n,13);
	memset(f,-0x3f,sizeof f);
	for(int i=1;i<=m;++i)f[i][0]=0;
	for(int i=n;i;--i){
		for(int j=n;j;--j)f[l[i]][j]=std::max(f[l[i]][j],f[l[i]][j-1]-s[i]+c[l[i]]);
		for(int j=l[i],k=n;j<m;++j,k>>=1)
			for(int p=0;p<=k;++p){
				f[j+1][p>>1]=std::max(f[j+1][p>>1],f[j][p]+c[j+1]*(p>>1));
//				printf("%d %d %d\n",j+1,p>>1,f[j+1][p>>1]);
			}
	}
	int ans=0;
	for(int i=1;i<=m;++i)ans=std::max(ans,f[i][1]);
	printf("%d\n",ans);
}