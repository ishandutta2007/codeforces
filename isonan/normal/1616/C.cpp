#include <cstdio>
#include <cstring>
#include <algorithm>

int t,n,a[71],f[71][71];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		memset(f,0,sizeof f);
		int ans=1;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j){
				f[i][j]=2;
				for(int k=1;k<i;++k)
					if((a[i]-a[k])*(j-i)==(a[j]-a[i])*(i-k))f[i][j]=std::max(f[i][j],f[k][i]+1);
				ans=std::max(ans,f[i][j]);
			}
		printf("%d\n",n-ans);
	}
}