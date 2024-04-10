#include<bits/stdc++.h>
using namespace std;
#define N 1001
int dd[N][N],d[N],g[N][N],n,MOD=998244353;
#define LL long long
LL f[N][N];
void work(int x){
	for(int i=1;i<=n;i++)dd[x][i]=(g[x][i]==1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[x][j]==i){
				f[x][x]=f[x][x]*d[j]%MOD;
				for(int k=1;k<=n;k++)if(g[j][k]==1){
					if(g[x][k]==i+1)dd[x][k]+=dd[x][j];
				}
			}
		}
	}
}
int e[2*N][2];
int main(){
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=1e6;
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		g[a][b]=g[b][a]=1;
		e[i][0]=a;
		e[i][1]=b;
		e[i+m][0]=b;
		e[i+m][1]=a;
	}
	
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=k&&j!=k&&i!=j)
	g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=n;i++){
		work(i);
	}
	for(int i=1;i<=n;i++)g[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(dd[i][j]==1||i==j){
			for(int k=1;k<=2*m;k++){
				int x=e[k][0],y=e[k][1];
				if(g[i][x]+1==g[i][y]&&g[j][x]+1==g[j][y]){
					++d[y];
				}
//					if(i==5&&j==6)cout<<x<<y<<g[i][y]<<g[j][x]<<endl; 
			}
			f[i][j]=1;
			for(int k=1;k<=n;k++){
				if(g[k][i]+g[k][j]!=g[i][j])f[i][j]=f[i][j]*d[k]%MOD;
				d[k]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%lld ",f[i][j]);
		}
		puts("");
	}
	
}