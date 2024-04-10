#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=5009;
const int S=1<<9;
int n,k;
int p[M],b[M];
int dp[M][S],c[M][M];
int calc(int x,int y,int s){
	if(x<=0)return 0;
	int rex=c[x][max(y-k,0)];
	for(int i=0;i<k;++i){
		if(s>>i&1){
			rex+=b[max(y-(k-1-i),0)]>b[x];
		}
	}
	return rex;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	k++;
	memset(dp,0X3F,sizeof(dp));
	dp[0][(1<<k)-1]=0;
	for(int i=1;i<=n;++i)cin>>p[i],b[p[i]]=i;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			c[i][j]=c[i][j-1]+(b[j]>b[i]);
		}
	}	
	for(int i=0;i<=n;++i){
		for(int s=0;s<1<<k;++s){
			if(!(s&(1<<(k-1))))continue;
			for(int j=0;j<k;++j){
				if(!(s>>j&1)){
					dp[i][s|1<<j]=min(dp[i][s|1<<j],dp[i][s]+calc(i-(k-1-j),i,s));
				}
			}
		}
		for(int j=i+1;j<=min(i+k,n);++j){
			for(int s=0;s<1<<k;++s){
				if(!(s&(1<<(k-1))))continue;
				int x=(1<<(j-i))-1,y=j-i;
				if((s&x)==x){
					int cost=calc(j,i,s);
					dp[j][s>>y|(1<<(k-1))]=min(dp[j][s>>y|(1<<(k-1))],dp[i][s]+cost);
				}
			}
		}
	}
	cout<<dp[n][(1<<k)-1]<<"\n";
	return 0;
}
/*
1 1
1

*/