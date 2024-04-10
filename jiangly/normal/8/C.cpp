#include<bits/stdc++.h>
using namespace std;
namespace looking_for_order{
	const int N=24,S=1<<24,mod=29,inf=1e9;
	int n,s;
	int x[N+1],y[N+1],dis[N+1][N+1],decision[S],Log2[mod],dp[S];
	inline int lowbit(int x){
		return x&-x;
	}
	void main(){
		scanf("%d%d",&x[0],&y[0]);
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d",&x[i],&y[i]);
		}
		for(int i=0;i<=n;++i){
			for(int j=0;j<=n;++j){
				dis[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			}
		}
		s=1<<n;
		for(int i=0;i<28;++i){
			Log2[(1<<i)%mod]=i;
		}
		for(int i=1;i<s;++i){
			int u=Log2[lowbit(i)%mod]+1,x=i-lowbit(i);
			dp[i]=2*dis[0][u]+dp[x];
			decision[i]=x;
			for(int y=x;y;y-=lowbit(y)){
				int v=Log2[lowbit(y)%mod]+1;
				dp[i]=dp[i]<dp[x^(1<<(v-1))]+dis[0][u]+dis[u][v]+dis[v][0]?dp[i]:(decision[i]=x^(1<<(v-1)),dp[x^(1<<(v-1))]+dis[0][u]+dis[u][v]+dis[v][0]);
			}
		}
		printf("%d\n",dp[s-1]);
		printf("0 ");
		for(int i=s-1,j;i;i=j){
			j=decision[i];
			int x=i^j;
			while(x){
				int y=Log2[lowbit(x)%mod]+1;
				x-=lowbit(x);
				printf("%d ",y);
			}
			printf("0 ");
		}
	}
}
int main(){
	looking_for_order::main();
	return 0;
}