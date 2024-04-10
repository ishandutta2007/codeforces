#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e6+9,p=1e9+7,inv2=(p+1)>>1;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
char In[1<<20],*Ss=In,*Tt=In;
//#define getchar() (Ss==Tt&&(Tt=(Ss=In)+fread(In,1,1<<20,stdin),Ss==Tt)?EOF:*Ss++)
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int fac[N],ifac[N],pw2[N],ipw2[N];
int qpow(int x,int base){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}
	return res;
}
inline void init(int sz){
	fac[0]=ipw2[0]=pw2[0]=1;
	rep(i,sz)fac[i]=fac[i-1]*i%p,
		ipw2[i]=ipw2[i-1]*inv2%p,
			pw2[i]=(pw2[i-1]+pw2[i-1])%p;
	ifac[sz]=qpow(fac[sz],p-2);
	Rof(i,sz,0)ifac[i-1]=ifac[i]*i%p;
}
int a[N],k,m,n,T;
signed main(){
	init(1000000);
	T=read();
	while(T--){
		n=read(),m=read(),k=read();
		if(n==m){
			printf("%lld\n",1ll*n*k%p);
			continue;
		}
		int ans=0;
		rep(i,m)(ans+=fac[n-i-1]*i%p*ipw2[n-i]%p*ifac[m-i]%p)%=p;
		printf("%lld\n",ans*k%p*ifac[n-m-1]%p);
	}
	return 0;
}