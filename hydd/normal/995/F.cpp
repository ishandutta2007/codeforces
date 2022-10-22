#include<cstdio>
using namespace std;
const int Mod=1e9+7;
int n,m,u,f[3100][3100],sum[3100][3100],C[3100][3100],inv[3100],g[3100];
int edgenum,vet[210000],Next[210000],Head[110000];
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs(int u){
    for (int i=Head[u];i;i=Next[i]){
        dfs(vet[i]);
        for (int j=1;j<=n;j++) f[u][j]=1ll*f[u][j]*sum[vet[i]][j]%Mod;
    }
    for (int i=1;i<=n;i++) sum[u][i]=(sum[u][i-1]+f[u][i])%Mod;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=2;i<=n;i++){
		scanf("%d",&u);
		addedge(u,i);
	}
    for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=1;
    dfs(1); C[0][0]=1;
    for (int i=1;i<=n;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    }
    inv[0]=1; inv[1]=1;
    for (int i=2;i<=n;i++) inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
    for (int i=2;i<=n;i++) inv[i]=1ll*inv[i-1]*inv[i]%Mod;
    for (int i=1;i<=n;i++){
        g[i]=f[1][i];
        for (int j=1;j<i;j++)
            g[i]=(g[i]-1ll*C[i-1][j-1]*g[j]%Mod+Mod)%Mod;
    }
    int ans=0;
    for (int i=1;i<=n&&i<=m;i++){
        int mul=inv[i];
        for (int j=m-i+1;j<=m;j++) mul=1ll*mul*j%Mod;
        //mul=C(m,i)
        ans=(ans+1ll*mul*g[i]%Mod)%Mod;
    }
    printf("%d\n",ans);
	return 0;
}