#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
const int mod=998244353;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,k,m,ans=1;
inline int max(int x,int y){
	return x>y?x:y;
}
int dp[N],mx[N],a[N],x[N],l[N],r[N],c[N];
int ppp;
inline int work(){
	int sum=1,j=0;dp[0]=1;
	for(int i=1;i<=n+1;i++){
		if(c[i]){dp[i]=0;continue;}
		while(j<=mx[i])sum=(sum-dp[j++])%mod;
		dp[i]=sum;
		sum=(sum+dp[i])%mod;
	}
	return dp[n+1];
}
signed main(){
	n=read(),k=read(),m=read();
	for(int i=1;i<=m;i++)l[i]=read(),r[i]=read(),x[i]=read();
	for(int p=0;p<k;p++){
		memset(mx,-1,sizeof mx);
		memset(c,0,sizeof c);
		for(int i=1;i<=m;i++){
			int val=(x[i]>>p)&1;
			c[l[i]]+=val;
			c[r[i]+1]-=val;
			if(!val)
				mx[r[i]+1]=max(mx[r[i]+1],l[i]-1);
		}
		for(int i=1;i<=n+1;i++)
			mx[i]=max(mx[i],mx[i-1]),
			c[i]+=c[i-1];
		ans=ans*work()%mod;
	}printf("%lld\n",(ans+mod)%mod);
	return 0;
}