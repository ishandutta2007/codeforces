#include<bits/stdc++.h>
#define eb emplace_back
#define ll long long
using namespace std;
const int N=1e7+9;
const int M=2e5+9;
int n,k,num=0;
int vis[N],pri[N],a[M];
int las[M],b[N];
int dp[M][23];
int s[23];
void work(){
	s[0]=0;
	scanf("%d%d",&n,&k);s[++s[0]]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		int x=a[i],y=1;
		while(x!=1){
			if(x/vis[x]%vis[x]==0)x=x/vis[x]/vis[x];
			else y*=vis[x],x/=vis[x];
		}
		las[i]=b[a[i]=y];
		b[y]=i;
		if(las[i])s[++s[0]]=las[i];
		sort(s+1,s+s[0]+1,[&](const int &l,const int&r){return l>r;});
		s[0]=min(s[0],k+1);
		for(int j=0;j<=k;++j){
			dp[i][j]=n+1;
			for(int l=0;l<=j&&l<s[0];++l){
				dp[i][j]=min(dp[i][j],dp[s[l+1]][j-l]+1);
			}
		}
	}
	for(int i=1;i<=n;++i)b[a[i]]=0;
	printf("%d\n",dp[n][k]);
}
int main(){
	for(int i=2;i<N;++i){
		if(!vis[i])vis[i]=i,pri[++num]=i;
		for(int j=1;1ll*i*pri[j]<N&&j<=num;++j){
			vis[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
1 0
1
*/