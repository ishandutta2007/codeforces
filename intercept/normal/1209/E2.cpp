#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=998244353;
const int M=2009;
int n,m;
int a[12][M],ma[M],id[M],dp[20][1<<12],g[1<<12];
void work(){
	cin>>n>>m;
	memset(ma,0,sizeof(ma));
	for(int i=0;i<n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			ma[j]=max(ma[j],a[i][j]);
		}
	}
	memset(dp,0,sizeof(dp));
	int ans=0;
	for(int i=1;i<=m;++i)id[i]=i;
	sort(id+1,id+m+1,[&](const int&l,const int&r){return ma[l]>ma[r];});
	for(int i=1;i<=min(n,m);++i){
		int x=id[i];
		for(int s=0;s<1<<n;++s){
			g[s]=0;
			for(int j=0;j<n;++j){
				if(s>>j&1){
					g[s]+=a[j][x];
				}
			}
		}
		for(int s=0;s<1<<n;++s){
			for(int t=s,j=0;j<n;++j,t=((t&1)<<(n-1))|(t>>1)){
				g[s]=max(g[s],g[t]);
			}
		}
		for(int s=0;s<1<<n;++s){
			dp[i][s]=g[s];
			for(int t=s;t;t=s&(t-1)){
				dp[i][s]=max(dp[i][s],dp[i-1][t]+g[s^t]);
			}
			ans=max(ans,dp[i][s]);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}

/*
1
2 3
2 5 7
4 2 4
*/