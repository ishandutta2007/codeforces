#include<bits/stdc++.h>
using namespace std;
unsigned long long dp[64];
long long read(){
	long long x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int t;
	t=read();
	dp[1]=1;
	for(int i=2;i<=63;i++)dp[i]=dp[i-1]*2+i;
	while(t--){
		long long n;
		unsigned long long ans=0;
		n=read();
		for(int i=62;i>=0;i--)
			if(n&(1ll<<i))
				ans=ans+dp[i]+i+1;
		printf("%llu\n",ans);
	}
	return 0;
}