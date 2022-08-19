#include <cstdio>
#include <bitset>
#include <cstring> 


int n,x[6001],y[6001],cnt[4][4];
bool vis[16][16];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",x+i,y+i),++cnt[x[i]%4][y[i]%4];
	long long ans=0;
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			for(int k=0;k<4;++k)
				for(int l=0;l<4;++l)
					if((k!=i||l!=j))
						ans+=((1ll*(cnt[i][j])*(cnt[i][j]-1))/2ll)*cnt[k][l];
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			ans+=(1ll*(cnt[i][j])*(cnt[i][j]-1)*(cnt[i][j]-2))/6ll;
	printf("%lld\n",ans);
}