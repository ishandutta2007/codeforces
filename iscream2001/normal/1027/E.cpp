#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long 
using namespace std;
const int inf=1e9;
const int N=2e5+10;
const int mod=998244353;
int n,K,cur=0;
LL f[2][510][510],g[510],sum[510];
int main(){
	scanf("%d%d",&n,&K);--K;
	f[cur][1][1]=1;
	for(int i=1;i<n;++i){
		memset(f[cur^1],0,sizeof(f[cur^1]));
		for(int j=1;j<=i;++j){
			for(int k=1;k<=j;++k){
				//cout<<f[cur][j][k]<<" ";
				if(!f[cur][j][k]) continue;
				f[cur^1][max(j,k+1)][k+1]+=f[cur][j][k];
				if(f[cur^1][max(j,k+1)][k+1]>mod)f[cur^1][max(j,k+1)][k+1]-=mod;
				f[cur^1][j][1]+=f[cur][j][k];
				if(f[cur^1][j][1]>mod) f[cur^1][j][1]-=mod;
			}
		//	cout<<endl;
		}
		cur^=1;
	}
	for(int j=1;j<=n;++j)
		for(int k=1;k<=j;++k){
			if(!f[cur][j][k]) continue;
			g[j]+=f[cur][j][k];
			if(g[j]>mod) g[j]-=mod;
		}
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+g[i];
		if(sum[i]>mod) sum[i]-=mod;
	}
	LL ans=0;
	int x;
	for(int i=1;i<=n;++i){
		x=K/i;
		x=min(x,n);
		//cout<<x<<endl;
		ans=(ans+g[i]*sum[x]%mod+g[i]*sum[x]%mod)%mod;
	}
	printf("%I64d\n",ans);
	return 0;
}