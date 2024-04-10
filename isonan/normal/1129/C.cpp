#include <cstdio>
#include <cstring>

int f[3010],m,a[3010],tot,P=1000000007,nxt[3010],ans[3010];
bool check[3010];
bool vis[3010][3010];
signed main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",a+i);
		if(i>=4)check[i-3]=!((a[i-3]==0&&a[i-2]==0&&a[i-1]==1&&a[i]==1)||(a[i-3]==0&&a[i-2]==1&&a[i-1]==0&&a[i]==1)||
			(a[i-3]==1&&a[i-2]==1&&a[i-1]==1&&a[i]==0)||a[i-3]==1&&a[i-2]==1&&a[i-1]==1&&a[i]==1);
	}
	for(int i=1;i<=m;i++){
		nxt[i]=i-1;
		int k=i-1;
		for(int j=i;j<=m;j++){
			if(j>i){
				while(k>i-1&&a[j]!=a[k+1])k=nxt[k];
				if(a[j]==a[k+1])++k;
				nxt[j]=k;
			}
			if(nxt[j]>i-1)vis[j-nxt[j]+i][j]=1;
		}
//		for(int j=i;j<=m;j++)printf("%d ",nxt[j]);putchar('\n');
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(vis[i-1][j])vis[i][j]=1;
	for(int i=1;i<=m;i++){
		memset(f,0,sizeof f);
		f[i+1]=1;
		for(int j=i;j;j--){
			f[j]=f[j+1];
			(f[j]+=f[j+2])%=P;
			(f[j]+=f[j+3])%=P;
			if(check[j])(f[j]+=f[j+4])%=P;
			if(!vis[j][i])(tot+=f[j])%=P;
		}
		printf("%d\n",tot);
	}
}