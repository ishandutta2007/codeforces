#include <cstdio>
#include <algorithm>
#define int long long

int f[2][210][210],g[2][210][210],a[210],b[210],c[210],n,Sa[210],Sb[210],t,K;
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d%d",&n,&t,&K);
	for(int i=1;i<=n;i++)scanf("%d%d%d",a+i,b+i,c+i);
	++n;
	a[n]=1e18,b[n]=0,c[n]=1e18;
	for(int i=1;i<=n;i++)Sa[i]=Sa[i-1]+a[i],Sb[i]=Sb[i-1]+b[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=t;j++){
			g[0][i][j]=g[1][i][j]=1e18;
			for(int k=0;k<j;k++){
				if(g[1][i][k]==1e18||g[0][i-1][j-k]==1e18)continue;
				int left=Sb[i]*k-g[1][i][k]*K;
//				printf("%d %d %d %lld %lld\n",i,j,k,left,g[i][k]+g[i-1][j-k]+((left+b[i]*(j-k)-1)/K));
				if(left%K+b[i]*(j-k)<=c[i]){
					int x=Sb[i-1]*(j-k)-g[0][i-1][j-k]*K,y=left+b[i]*(j-k),z=std::max((y-c[i]+K-1)/K,0ll);
					g[0][i][j]=std::min(g[0][i][j],g[1][i][k]+g[0][i-1][j-k]+z);
//					printf("%d %d %d %d %lld %lld %lld\n",i,j,k,left,x,y,g[1][i][k]+g[0][i-1][j-k]+z+(x+K-1)/K);
					if(((x+K-1)/K)*K<=x+y-z*K)g[1][i][j]=std::min(g[1][i][j],g[1][i][k]+g[0][i-1][j-k]+z+(x+K-1)/K);
				}
			}
			if(g[0][i-1][j]!=1e18){
				int left=b[i]*j;
				if(left<=c[i]){
//					printf("%d %d\n",i,j);
					int x=Sb[i-1]*j-g[0][i-1][j]*K,y=left,z=std::max((y-c[i]+K-1)/K,0ll);
					g[0][i][j]=std::min(g[0][i][j],g[0][i-1][j]);
					if(((x+K-1)/K)*K<=x+y)g[1][i][j]=std::min(g[1][i][j],g[0][i-1][j]+(x+K-1)/K);
				}
			}
//			printf("%d %d %lld %lld\n",i,j,g[0][i][j],g[1][i][j]);
		}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=t;j++){
			f[0][i][j]=f[1][i][j]=1e18;
			for(int k=0;k<j;k++){
				if(f[1][i][k]==1e18||g[0][i-1][j-k]==1e18)continue;
				int left=Sa[i]+Sb[i]*k-f[1][i][k]*K;
				if(left%K+b[i]*(j-k)<=c[i]){
					int x=Sb[i-1]*(j-k)-g[0][i-1][j-k]*K,y=left+b[i]*(j-k),z=std::max((y-c[i]+K-1)/K,0ll);
					f[0][i][j]=std::min(f[0][i][j],f[1][i][k]+g[0][i-1][j-k]+z);
					if(((x+K-1)/K)*K<=x+y-z*K)f[1][i][j]=std::min(f[1][i][j],f[1][i][k]+g[0][i-1][j-k]+z+(x+K-1)/K);
				}
			}
			if(f[0][i-1][j]!=1e18){
				int left=a[i]+b[i]*j;
				if(left<=c[i]){
//					printf("%d %d\n",i,j);
					int x=Sa[i-1]+Sb[i-1]*j-f[0][i-1][j]*K,y=left,z=std::max((y-c[i]+K-1)/K,0ll);
					f[0][i][j]=std::min(f[0][i][j],f[0][i-1][j]);
					if(((x+K-1)/K)*K<=x+y)f[1][i][j]=std::min(f[1][i][j],f[0][i-1][j]+(x+K-1)/K);
				}
			}
//			printf("%d %d %lld %lld\n",i,j,f[0][i][j],f[1][i][j]);
		}
	printf("%lld\n",f[0][n][t]);
}