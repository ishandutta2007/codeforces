#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010,mod=1000000007;
int i,j,k,n,m,T,dp[11][maxn];
int main(){
	for(i=0;i<=9;i++)dp[i][0]=1;
	for(i=1;i<maxn;i++)
		for(j=0;j<=9;j++)dp[j][i]=(j==9?(dp[1][i-1]+dp[0][i-1])%mod:dp[j+1][i-1]);
	cin>>T;
	while(T--){
		n=read();m=read();ll ans=0;
		for(ll i=1;i<=n;i*=10){
			ans+=dp[n%(i*10)/i][m];
//			cout<<dp[n%(i*10)/i][m]<<' '<<n%(i*10)/i<<endl;
		}printf("%lld\n",ans%mod);
	}
	return 0;
}