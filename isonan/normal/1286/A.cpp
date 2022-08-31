#include <cstdio>
#include <cstring>
#include <algorithm>

int n,a[101],f[101][101][2],cnt[2];
bool vis[101];
int main(){
	scanf("%d",&n);
	memset(f,0x7f7f7f7f,sizeof f);
	for(int i=1;i<=n;i++)scanf("%d",a+i),vis[a[i]]=1;
	for(int i=1;i<=n;i++)if(!vis[i])++cnt[i%2];
	f[0][0][0]=f[0][0][1]=0;
	for(int i=1;i<=n;i++){
		if(a[i]){
			for(int j=0;j<=i;j++)
				f[i][j][a[i]%2]=std::min(f[i-1][j][(a[i]%2)^1]+1,f[i-1][j][a[i]%2]);
		}
		else{
			for(int j=0;j<=i&&j<=cnt[1];j++){
				if(j)f[i][j][1]=std::min(f[i][j][1],std::min(f[i-1][j-1][0]+1,f[i-1][j-1][1]));
				f[i][j][0]=std::min(f[i][j][0],std::min(f[i-1][j][1]+1,f[i-1][j][0]));
			}
		}
	}
	printf("%d\n",std::min(f[n][cnt[1]][0],f[n][cnt[1]][1]));
}