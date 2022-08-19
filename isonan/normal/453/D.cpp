#include <bits/stdc++.h>
#define int long long

namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;
int P;
typedef long long ll;
inline ll ksc(ll x, ll y, ll mod){
    return ( x * y - (ll) ( (long double) x / mod*y )*mod + mod ) % mod;     
}
inline int mul(const int &a,const int &b){return ksc(a,b,P);}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,long long b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int m,lim;
int t1[1048576],t2[1048576],b[21];
long long t;
void FWT(int *a){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;++k){
				const int Ny=a[i+j+k];
				a[i+j+k]=sub(a[j+k],Ny);
				a[j+k]=add(a[j+k],Ny);
			}
}
signed main(){
	qio>>m>>t>>P;
	P<<=m;
	lim=1<<m;
	for(int i=0;i<lim;++i)qio>>t1[i];
	for(int i=0;i<=m;++i)qio>>b[i];
	for(int i=0;i<lim;++i)t2[i]=b[__builtin_popcount(i)];
	FWT(t1);
	FWT(t2);
	for(int i=0;i<lim;++i)t1[i]=mul(t1[i],qsm(t2[i],t));
	FWT(t1);
	for(int i=0;i<lim;++i)qio<<(t1[i]>>m)<<'\n';
}