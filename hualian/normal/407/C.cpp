#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int p=1e9+7;
const int N=1e5+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m;
int A[N],a[N][103];
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
int fac[N],ifac[N];
void init(int n=N-1){
	fac[0]=ifac[0]=1;rep(i,n)fac[i]=fac[i-1]*i%p,ifac[i]=inv(fac[i]);
	assert(fac[10]*ifac[10]%p==1);
}
int C(int n,int m){return fac[n]*ifac[m]%p*ifac[n-m]%p;}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();init();
	rep(i,n)A[i]=read();
	rep(i,m){
		int l=read(),r=read(),k=read();
		a[l][k]++;
		For(i,0,k){a[r+1][i]=(a[r+1][i]-C(r-l+k-i,k-i))%p;}
	}
	Rof(j,101,0)rep(i,n)
		a[i][j]=(a[i][j]+a[i][j+1]+a[i-1][j])%p;
	rep(i,n)printf("%lld ",((A[i]+a[i][0])%p+p)%p);
	return 0;
}