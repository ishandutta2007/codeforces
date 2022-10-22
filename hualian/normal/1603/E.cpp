#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=210;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,p,ans,S; 
int fac[N],ifac[N];
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=1ll*res*x%p;
		x=1ll*x*x%p;
		base>>=1;
	}return res;
}
void init(int n){
	fac[0]=1;rep(i,n)fac[i]=1ll*fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);Rof(i,n-1,0)ifac[i]=1ll*ifac[i+1]*(i+1)%p;
	assert(1ll*fac[10]*ifac[10]%p==1);
}
int vis[N][N][51],dp[N][N][51];
int dfs(int dep,int sum,int last,int lim){// 
	int &res=dp[dep][sum][last];
	if(res>=0)return res;res=0; 
	if(last<=lim-1&&dep<last)return res;// 
	if(last==lim){if(dep<n)res=ifac[n-dep];return res;}//S
	int A=lim-last;// j
	for(int cnt=0;dep+cnt<=n&&sum+cnt*A<=S;cnt++)
		(res+=1ll*dfs(cnt+dep,sum+cnt*A,last+1,lim)*ifac[cnt]%p)%=p;
	return res;
}//ai=i 
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),p=read();init(N-1);
	ans=0;
	For(mx,0,32){
		memset(dp,-1,sizeof dp);
		S=n+1-mx;
		(ans+=dfs(0,0,0,mx))%=p;
	}
	cout<<1ll*ans*fac[n]%p<<endl;
	return 0;
}