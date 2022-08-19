#include <cstdio>
#include <algorithm>

int n,m,f[101][101],calc[110][110];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,l,r;j<=k;j++)
			scanf("%d%d",&l,&r),++calc[l][r];
	}
	for(int i=m;i;i--)
		for(int j=1;j<=m;j++)
			calc[i-1][j]+=calc[i][j];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			calc[i][j+1]+=calc[i][j];
	for(int i=m;i;i--)
		for(int j=i;j<=m;j++){
			for(int k=i;k<=j;k++)
				f[i][j]=std::max((calc[i][j]-calc[i][k-1]-calc[k+1][j])*(calc[i][j]-calc[i][k-1]-calc[k+1][j])+f[i][k-1]+f[k+1][j],f[i][j]);
		}
	printf("%d\n",f[1][m]);
}