#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct sb{
	int l,r,num;
}s[500500];
int i,j,k,n,m,a[500500],dp[500500],res,ed,ans,tmp;

int main(){
	scanf("%d",&n);res=n;
	dp[0]=0;
	for(i=1;i<=500000;i++){
		s[i].l=11451419;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[a[i]].l=min(s[a[i]].l,i);
		s[a[i]].r=max(s[a[i]].r,i);
		s[a[i]].num++;
	}
	for(i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(i==s[a[i]].r){dp[i]=max(dp[s[a[i]].l-1]+s[a[i]].num,dp[i]);}
	}
	ans=dp[n];
	for(i=1;i<=n;i++){
		ans=max(ans,dp[i-1]+s[a[i]].num);s[a[i]].num--;
	}
	printf("%d",n-ans);
}