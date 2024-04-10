#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct hb{
	int l,r,d,x;
	bool operator<(const hb a)const{return (x==a.x)?d<a.d:x<a.x;}
}h[100500];
bool cmp(hb a,hb b){return a.l<b.l;}
priority_queue<hb> q;

int n,m,i,j,k,it=1;
ll dp[100500][205],res;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	memset(dp,63,sizeof(dp));
	res=dp[1][0];
	dp[1][0]=0;
	for(i=1;i<=k;i++){
		scanf("%d%d%d%d",&h[i].l,&h[i].r,&h[i].d,&h[i].x);
	}
	sort(h+1,h+k+1,cmp);
	h[k+1].l=114514;
	for(i=1;i<=n;i++){
		while(h[it].l<=i){q.push(h[it]);it++;}
		if(q.empty()){
			for(j=0;j<=m;j++){
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			}
			continue;
		}
		for(j=0;j<=m;j++){
			dp[q.top().d+1][j]=min(dp[q.top().d+1][j],dp[i][j]+q.top().x);
			dp[i+1][j+1]=min(dp[i][j],dp[i+1][j+1]);
		}
		while(!q.empty()&&q.top().r<=i){q.pop();}
	}
	for(i=0;i<=m;i++){
		res=min(res,dp[n+1][i]);
	}
	printf("%lld",res);
}