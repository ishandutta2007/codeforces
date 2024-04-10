#include <cstdio>
#include <algorithm>

int n,m,f[5010][5010];
char a[5010],b[5010];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",a+1,b+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			f[i][j]=-2+4*(a[i]==b[j]);
			f[i][j]=std::max(f[i][j],f[i-1][j]-1);
			f[i][j]=std::max(f[i][j],f[i][j-1]-1);
			f[i][j]=std::max(f[i][j],f[i-1][j-1]-2+4*(a[i]==b[j]));
			ans=std::max(ans,f[i][j]);
		}
	printf("%d\n",ans);
}