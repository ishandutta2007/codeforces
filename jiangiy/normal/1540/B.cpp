#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=205,P=1000000007;
int pow(int a,int b){
	int r=1;
	for(;b;b>>=1,a=(LL)a*a%P) if(b&1)r=(LL)r*a%P;
	return r;
}
std::vector<int>p[N];
int n,f[N][N],po[N],fa[N],dep[N],rk,rc;
LL ans;
void dfs(int x){
	for(int y:p[x]) if(y!=fa[x]){
		fa[y]=x;
		dfs(y);
	}
}
int cal(int x,int y){
	if(!x)return 0;
	if(!y)return 1;
	return(LL)f[x+y-1][x]*po[x+y-1]%P;
}
void dfs2(int x,int d){
	if(x<rk){
		ans+=cal(d,rc);
	}
	for(int y:p[x]) if(y!=fa[x])dfs2(y,d+1);
}
int main(){
	scanf("%d",&n);
	po[0]=1;
	for(int i=1;i<=n;i++)po[i]=(po[i-1]&1?po[i-1]+P:po[i-1])>>1;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)f[i][j]=((f[i-1][j]+3ll*f[i-1][j-1]-(i>=2?2ll*f[i-2][j-1]+(j>=2?2ll*f[i-2][j-2]:0ll):0ll))%P+P)%P;
	}
	for(int i=1;i<=n;i++)f[i][i]=(LL)(f[i][i]-1)*po[1]%P;
	for(int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		fa[i]=0;
		dfs(i);
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)dep[k]=0;
			for(int k=j,c=1;k;k=fa[k],c++){
				rk=j,rc=c-1;
				dep[k]=c;
				for(int z:p[k]) if(!dep[z]&&z!=fa[k]){
					dfs2(z,1);
				}
			}
		}
	}
	ans=(LL)ans%P*pow(n,P-2)%P;
	printf("%lld\n",ans);
}