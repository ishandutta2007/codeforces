#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int p=1e9+7;
const int N=1e6+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int ans,n,cnt1,cnt2,a[N],used[N];
int fac[N],ifac[N];
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
	assert(fac[10]*ifac[10]%p==1);
}
int C(int n,int m){return fac[n]*ifac[m]%p*ifac[n-m]%p;}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	rep(i,n=read())a[i]=read(),cnt1+=a[i]==-1;
	init();
	rep(i,n)if(a[i]!=-1)used[a[i]]=1;
	rep(i,n)if(a[i]==-1&&(!used[i]))cnt2++;//
	For(i,0,cnt2)ans=(ans+inv(-1,i)*C(cnt2,i)*fac[cnt1-i])%p;
	cout<<(ans+p)%p<<endl;
	return 0;
}