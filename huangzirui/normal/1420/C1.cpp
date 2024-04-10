#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=300010;
int i,j,k,n,m,a[maxn];ll dp[maxn][2],ans;
int main(){
	int T=read();
	while(T--){
		n=read();m=read();
		for(i=1;i<=n;i++)a[i]=read();ans=0;
		for(i=0;i<=n;i++)dp[i][0]=dp[i][1]=-1e9;
		dp[0][0]=0;
		ll Max0=0,Max1=-1e9;
		for(i=1;i<=n;i++){
			dp[i][1]=Max0+a[i];
			dp[i][0]=Max1-a[i];
			Max0=max(Max0,dp[i][0]);
			Max1=max(Max1,dp[i][1]);
			ans=max(ans,dp[i][1]);
		}printf("%I64d\n",ans);
	}
	return 0;
}