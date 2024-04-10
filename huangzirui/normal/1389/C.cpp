#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
int i,j,k,n,m;
int num[11],dp[maxn][2];
string S;
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>S;n=S.size();
		memset(num,0,sizeof(num));
		int Max=0;
		for(i=0;i<n;i++){
			int sum=S[i]-'0';
			num[sum]++;
		}for(i=0;i<=9;i++)Max=max(Max,num[i]);
		int ans=n-Max;
		for(int a=0;a<=9;a++)
			for(int b=0;b<=9;b++){
				for(i=0;i<=n;i++)dp[i][0]=dp[i][1]=1e9;
				dp[0][0]=0;
				for(i=1;i<=n;i++){
					dp[i][0]=dp[i-1][0]+1;dp[i][1]=dp[i-1][1]+1;
					int sum=S[i-1]-'0';
					if(sum==a)dp[i][0]=min(dp[i][0],dp[i-1][1]);
					if(sum==b)dp[i][1]=min(dp[i][1],dp[i-1][0]);
				}ans=min(ans,dp[n][0]);
			}
		printf("%d\n",ans); 
	}
	return 0;
}