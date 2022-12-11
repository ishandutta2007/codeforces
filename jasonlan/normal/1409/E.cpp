#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
const int maxn=201000;
int n,k,ans;
int a[maxn],nxt[maxn],dp[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main()
{
	for(register int T=read();T;--T){
		n=read();k=read();
		for(register int i=0;i<n;++i)
			a[i]=read();
		for(register int i=0;i<n;++i)
			read();
		sort(a,a+n);
		ans=0;
		dp[n]=0;
		for(register int i=n-1;~i;--i){
			nxt[i]=upper_bound(a+i,a+n,a[i]+k)-a-1;
			dp[i]=max(nxt[i]-i+1,dp[i+1]);
		}
		for(register int i=0;i<n;++i)
			ans=max(ans,nxt[i]-i+1+dp[nxt[i]+1]);
		printf("%d\n",ans);
	}
	return 0;
}