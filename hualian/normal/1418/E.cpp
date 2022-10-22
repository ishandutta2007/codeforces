#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
const int p=998244353;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int fac[N],ifac[N];
int C(int n,int m){return fac[n]*ifac[m]%p*ifac[n-m]%p;}
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
void init(int n=N-1){
	fac[0]=1;rep(i,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);
	Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
	assert(ifac[10]*fac[10]%p==1);
}
int a[N],sum[N];
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int n=read(),m=read();init();
	rep(i,n)a[i]=read();
	sort(a+1,a+1+n);
	rep(i,n)sum[i]=(sum[i-1]+a[i])%p;
	rep(i,m){
		int x=read(),y=read(),ans=0;//xy
		int cnt=lower_bound(a+1,a+1+n,y)-a-1;
		cnt=n-cnt;
		//
		if(cnt<=x);// 
		else ans+=(cnt-x)*fac[cnt-1]%p*(sum[n]+p-sum[n-cnt])%p*C(n,cnt)%p*fac[n-cnt]%p;
				//               
		if(cnt<x||cnt==n);// 
		else ans+=(cnt+1-x)*fac[cnt]%p*sum[n-cnt]%p*C(n,cnt+1)%p*fac[n-cnt-1]%p;
				//                           
		ans%=p;cout<<ans*ifac[n]%p<<endl;
	}
	return 0;
}