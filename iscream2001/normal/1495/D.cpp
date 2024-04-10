#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const int INF=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}

int n,m,cnt;
int l[2000],r[2000];
int dis[700][700];
int vis[700][700];
int du[700][700];
int tt[700],dp[700];
void MAIN(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=INF;
		}
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&l[i],&r[i]);
		dis[l[i]][r[i]]=dis[r[i]][l[i]]=1;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i!=j&&i!=k&&j!=k){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	LL ans;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=0;k<=n;++k) {
				tt[k]=0;
				dp[k]=0;
			}
			for(int k=1;k<=m;++k){
				if(dis[i][l[k]]==dis[i][r[k]]) continue;
				if(dis[i][l[k]]>dis[i][r[k]]) u=l[k],v=r[k];
				else u=r[k],v=l[k];
				if(dis[i][u]+dis[j][u]>dis[i][j]){
					du[u][v]=1;
				}
			}
			for(int k=1;k<=m;++k){
				if(dis[j][l[k]]==dis[j][r[k]]) continue;
				if(dis[j][l[k]]>dis[j][r[k]]) u=l[k],v=r[k];
				else u=r[k],v=l[k];
				if(du[u][v]) {
					if(dis[i][u]+dis[j][u]>dis[i][j]){
						++tt[u];
					}
				}
			}
			for(int k=1;k<=m;++k){
				if(dis[i][l[k]]==dis[i][r[k]]) continue;
				if(dis[i][l[k]]>dis[i][r[k]]) u=l[k],v=r[k];
				else u=r[k],v=l[k];
				if(dis[i][u]+dis[j][u]>dis[i][j]){
					du[u][v]=0;
				}
			}
			ans=1;
			for(int k=1;k<=n;++k){
				if(dis[i][k]+dis[j][k]>dis[i][j])ans=ans*(LL)tt[k]%P;
				else{
					if(!dp[dis[i][k]]){
						dp[dis[i][k]]=1;
					}
					else{
						ans=0;
					}
				}
			}
			printf("%lld ",ans);
		}
		puts("");
	}
	return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}