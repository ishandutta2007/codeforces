#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T,dp[maxn],last[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		last[0]=last[1]=0;
		string S1,S2;
		cin>>S1>>S2;
		for(i=1;i<=n;i++){
			int w1=S1[i-1]-'0',w2=S2[i-1]-'0';
			last[w1]=i;last[w2]=i;
			dp[i]=dp[i-1];
			if(last[0])dp[i]=max(dp[i],dp[min(i-1,last[0]-1)]+1);
			if(last[0] && last[1])dp[i]=max(dp[i],dp[min(i-1,min(last[0]-1,last[1]-1))]+2);
		}printf("%d\n",dp[n]);
	}
	return 0;
}