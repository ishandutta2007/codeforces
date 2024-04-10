#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
using namespace std;
const int M=5e6+9;
int n,m;
int dp[M];
int cnt[M];
bool vis[M];
void work(){
	scanf("%d%d",&n,&m);
	int mi=m;
	for(int i=1;i<=m;++i)vis[i]=cnt[i]=0;
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		vis[x]=1;
		cnt[x]=1;
		mi=min(mi,x);
	}
	int ans=m;
	for(int i=m,r=m;i>=1;--i){
		dp[i]=i;
		for(ll j=1ll*i*i;j<=m;j+=i){
			if(vis[j])cnt[dp[j]]--;
			dp[j]=min(dp[j],max(i,dp[j/i]));
			if(vis[j])cnt[dp[j]]++;
		}
		while(cnt[r]==0)r--;
		if(i<=mi)ans=min(ans,r-i);
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
1 50
3





*/