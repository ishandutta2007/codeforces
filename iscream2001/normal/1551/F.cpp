#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=1e9+7;
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
void init(){
	return;
}

int n,K;
vector<int> V[110];
LL dp[110][110];
LL num[110];
void dfs(int x,int fa,int dep){
	++num[dep];
	for(int i=0;i<V[x].size();++i){
		if(V[x][i]!=fa){
			dfs(V[x][i],x,dep+1);
		}
	}
	return;
}
void MAIN(){
	int u,v;
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i){
		V[i].clear();
	}
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	if(K==2){
		printf("%d\n",n*(n-1)/2);
		return;
	}
	LL ans=0;
	for(int i=1;i<=n;++i){
		memset(dp,0,sizeof(dp));
		for(int k=1;k<=n;++k) dp[k][0]=1;
		for(int j=0;j<V[i].size();++j){
			for(int k=1;k<=n;++k) num[k]=0;
			dfs(V[i][j],i,1);
			for(int k=1;k<=n;++k){
				for(int o=K;o>=1;--o){
					pls(dp[k][o],dp[k][o-1]*num[k]%P);
				}
			}
		}
		for(int k=1;k<=n;++k){
			pls(ans,dp[k][K]);
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
//	freopen("1.in","r",stdin);
	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;	
}
/*
*/