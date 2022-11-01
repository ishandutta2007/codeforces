#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=105;
int n,k,x[N],y[N],p[N*2];
bool vis[N*2];
bool chk(int a,int b){
	int u=x[b],v=y[b];
	bool ut=u>=x[a]&&u<=y[a];
	bool vt=v>=x[a]&&v<=y[a];
	return ut!=vt;
}
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n*2;i++)vis[i]=0;
		for(int i=1;i<=k;i++){
			scanf("%d%d",x+i,y+i);
			vis[x[i]]=vis[y[i]]=1;
			if(x[i]>y[i])std::swap(x[i],y[i]);
		}
		int ans=0,tot=0;
		for(int i=1;i<=k;i++) for(int j=1;j<=i-1;j++)ans+=chk(i,j);
		for(int i=1;i<=n*2;i++)p[i]=p[i-1]+!vis[i];
		tot=p[n*2];
		for(int i=1;i<=k;i++){
			int t=p[y[i]]-p[x[i]];
			ans+=std::min(tot-t,t);
		}
		tot/=2;
		ans+=tot*(tot-1)/2;
		printf("%d\n",ans);
	}
}