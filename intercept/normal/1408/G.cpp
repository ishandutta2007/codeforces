#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
const int M=1509;
int n;
int a[M][M],dp[M][M],c[M],f[M],s[M],e[M];
pii b[M*M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		f[i]=i;dp[i][1]=s[i]=1;
		for(int j=1;j<=n;++j)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j)b[a[i][j]]=make_pair(i,j);
	}
	for(int i=1;i<=n*(n-1)/2;++i){
		int u=b[i].first,v=b[i].second;
		u=find(u);
		v=find(v);
		if(u!=v){
			memset(c,0,sizeof(c));
			for(int j=s[u];j>=1;--j){
				for(int k=s[v];k>=1;--k){
					c[j+k]=(c[j+k]+1ll*dp[u][j]*dp[v][k]%mod)%mod;
				}
			}
			f[v]=u;
			s[u]+=s[v];
			e[u]+=e[v]+1;
			for(int j=1;j<=s[u];++j)dp[u][j]=c[j];
		}
		else e[u]++;
		if(e[u]==s[u]*(s[u]-1)/2)dp[u][1]++;
	}
	for(int i=1;i<=n;++i)printf("%d%c",dp[find(1)][i]," \n"[i==n]);
	return 0;
}