#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=400010;
struct edge{
	int next,to;
}a[maxn*2];
int head[maxn],len;
void add(int x,int y){
	a[++len]={head[x],y};
	head[x]=len;
}
int i,j,k,n,m,dp[maxn][3],Max[maxn][2],sum[maxn];
void dfs(int now,int fa){
	sum[now]=1;
	for(int i=head[now];i;i=a[i].next){
		int u=a[i].to;
		if(u==fa)continue;
		dfs(u,now);
		sum[now]+=sum[u];
		int Sum=(sum[u]<=n/2? sum[u]:dp[u][0]);
		if(Sum>dp[now][0]){
			dp[now][2]=dp[now][0];
			dp[now][0]=Sum;
			dp[now][1]=u;
		}else
		if(Sum>dp[now][2])dp[now][2]=Sum;
		if(sum[u]>Max[now][0]){
			Max[now][0]=sum[u];
			Max[now][1]=u;
		}
	}
	if(n-sum[now]>Max[now][0])Max[now][0]=n-sum[now],Max[now][1]=-1;
	return;
}
int is[maxn];
void dfs2(int now,int fa,int last){
	if(last==0 && now!=1)last=1;
	/*
	cout<<"dfs now="<<now<<" fa="<<fa<<" last="<<last<<endl;
	cout<<dp[now][0]<<' '<<dp[now][1]<<' '<<dp[now][2]<<' '<<Max[now][0]<<' '<<Max[now][1]<<endl;
	*/
	for(int i=head[now];i;i=a[i].next){
		int u=a[i].to;
		if(u==fa)continue;
		int Next;
		if(u==dp[now][1])Next=max(last,dp[now][2]);
		else Next=max(last,dp[now][0]);
		if(n-sum[u]<=n/2)Next=max(Next,n-sum[u]);
		dfs2(u,now,Next);
	}
	if(Max[now][1]<0){
		if(Max[now][0]-last<=n/2)is[now]=1;
	}else
		if(Max[now][0]-dp[Max[now][1]][0]<=n/2)is[now]=1;
}
int main() {
	cin>>n;
	for(i=1;i<n;i++){
		int x,y;
		x=read();y=read();
		add(x,y);add(y,x);
	}
	dfs(1,0);
	dfs2(1,0,0);
	for(i=1;i<=n;i++)printf("%d ",is[i]);
	cout<<endl;
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}