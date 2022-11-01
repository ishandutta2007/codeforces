#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100005;
int t,n,s[N];
LL p[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		std::sort(s+1,s+n+1);
		for(int i=1;i<=n;i++)p[i]=p[i-1]+s[i];
		LL ans=0;
		for(int i=2;i<=n;i++)ans+=s[i]*(LL)(i-1)-p[i-1];
		ans=s[n]-ans;
		printf("%lld\n",ans);
	}
}