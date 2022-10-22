#include <cstdio>
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=200;
const int Mod=1000000007;
const int inv_2=(Mod+1)>>1;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int dep[Maxn+5];
int lis[Maxn+5][Maxn+5],len[Maxn+5];
int lca[Maxn+5][Maxn+5];
int fac[Maxn+5],inv_f[Maxn+5];
int f[Maxn+5][Maxn+5],g[Maxn+5][Maxn+5],s[Maxn+5][Maxn+5];
int C(int n,int m){
	return 1ll*fac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int inv_C(int n,int m){
	return 1ll*inv_f[n]*fac[m]%Mod*fac[n-m]%Mod;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=Maxn;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	inv_f[Maxn]=find_inv(fac[Maxn]);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
	f[1][0]=inv_2,g[0][1]=inv_2;
	for(int i=0;i<=Maxn;i++){
		for(int j=0;j+i<=Maxn;j++){
			if(i==0&&j==0){
				continue;
			}
			if(i==1&&j==0){
				continue;
			}
			if(i==0&&j==1){
				continue;
			}
			if(i>0){
				f[i][j]=(1ll*inv_2*f[i-1][j]+1ll*inv_2*g[i-1][j])%Mod;
			}
			if(j>0){
				g[i][j]=(1ll*inv_2*f[i][j-1]+1ll*inv_2*g[i][j-1])%Mod;
			}
			/*f[i][j]=C(i+j-1,i);
			f[i][j]=1ll*f[i][j]*inv_C(i+j,i)%Mod;*/
		}
	}
	for(int i=1;i<=Maxn;i++){
		s[i][0]=f[i][0];
		for(int j=1;j+i<=Maxn;j++){
			s[i][j]=(s[i][j-1]+f[i][j])%Mod;
		}
	}
}
void init_dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	len[u]=0;
	lis[u][++len[u]]=u;
	lca[u][u]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
		for(int j=1;j<=len[u];j++){
			for(int k=1;k<=len[v];k++){
				lca[lis[u][j]][lis[v][k]]=lca[lis[v][k]][lis[u][j]]=u;
			}
		}
		for(int j=1;j<=len[v];j++){
			lis[u][++len[u]]=lis[v][j];
		}
	}
}
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		init_dfs(i,0);
		for(int u=1;u<=n;u++){
			for(int v=1;v<u;v++){
				if(lca[u][v]==v){
					continue;
				}
				if(lca[u][v]==u){
					ans=(ans+1)%Mod;
					continue;
				}
				int dis_u=dep[u]-dep[lca[u][v]],dis_v=dep[v]-dep[lca[u][v]];
				ans=(ans+s[dis_u][dis_v-1])%Mod;
			}
		}
	}
	ans=1ll*ans*find_inv(n)%Mod;
	printf("%d\n",ans);
	return 0;
}