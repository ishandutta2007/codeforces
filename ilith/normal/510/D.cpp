#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=100010;
namespace Reimu_Kawaii{
	char buf[1<<20],obuf[1<<20],*p1,*p2,*p3=obuf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
	#define putchar(x) (p3-obuf<1000000)?(*p3++=x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x)
	inline int read(){
		int x=0;char c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
		return x;
	}
	inline void write(int x){
		static char buf[15];
		static int len=-1;
		do buf[++len]=x%10+48,x/=10;while(x);
		while(len>=0)putchar(buf[len]),--len;
		putchar(' ');
	}
	inline void flush(){fwrite(obuf,p3-obuf,1,stdout),exit(0);}
	#undef getchar
	#undef putchar
}using namespace Reimu_Kawaii;
#define fi first
#define se second
int n,l[N],c[N],vis[N],ans=1e9;
vector<int>pri,h[N];
int dp[N];
signed main(){
	FOR(i,vis[1]=1,N-5){
		if(!vis[i])pri.pbk(i);
		for(rgi j:pri){
			if(i*j>N-5)break;
			vis[i*j]=1;
			if(i%j==0)break;
		}
	}
	FOR(i,1,n=read()){
		rgi x=l[i]=read();
		for(rgi p:pri)if(1ll*p*p<=l[i]){
			if(x%p==0)h[i].pbk(p);
			while(x%p==0)x/=p;
		}
		if(x>1)h[i].pbk(x);
	}
	FOR(i,1,n)c[i]=read();
	FOR(i,1,n){
		rgi S=h[i].size(),D=(1<<S)-1;
		memset(dp,31,sizeof dp),dp[0]=0;
		FOR(j,1,n)if(j!=i){
			rgi s=0;
			FOR(k,0,S-1)if(l[j]%h[i][k])s|=(1<<k);
			dp[s]=min(dp[s],c[j]);
		}
		FOR(s,1,D)for(rgi k=s;k;k=(k-1)&s)dp[D^s]=min(dp[D^s],dp[k^D]);
		FOR(s,1,D)for(rgi k=s;k;k=(k-1)&s)dp[s]=min(dp[s],dp[k]+dp[s^k]);
		ans=min(ans,dp[D]+c[i]);
	}
	if(ans>1e7)puts("-1");
	else write(ans),flush();
}