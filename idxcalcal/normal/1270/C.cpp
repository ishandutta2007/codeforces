#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline ll readl() {
  ll ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline int Read(char*s) {
	int top=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) s[++top]=ch,ch=gc();
	return top;
}
namespace modular {
  const int mod=1e9+7;
  inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
  inline int dec(int a,int b) { return a<b?a-b+mod:a-b; }
  inline int mul(int a,int b) { return (ll)a*b%mod; }
  inline void Add(int&a,int b) { a=a+b<mod?a+b:a+b-mod; }
  inline void Dec(int&a,int b) { a=a<b?a-b+mod:a-b; }
  inline void Mul(int&a,int b) { a=(ll)a*b%mod; }
  inline int ksm(int a,int p) { int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
  inline int Inv(int a) { return ksm(a,mod-2); }
}
using namespace modular;
const int N=1e5+5;
int n;
ll vl[N],x,y,a,b,c;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read();tt;--tt) {
  	n=read();
  	x=y=a=b=c=0;
  	for(ri i=1;i<=n;++i) vl[i]=read(),x+=vl[i],y^=vl[i];
  	ll _x=x,_y=y;
  	for(ri v1,v2,i=0;i<63;++i) {
  		v1=x>>i&1,v2=y>>i&1;
  		if(v1) {
  			if(v2) {
  				x+=1ll<<(i+2);
  				x-=1ll<<i;
  				a^=1ll<<i;
  				b^=1ll<<i;
  				c^=1ll<<i;
  				continue;
				}
				else {
					a^=1ll<<i;
					continue;
				}
			}
			else {
				if(!v2) continue;
				a^=1ll<<i;
				b^=1ll<<i;
			}
		}
		cout<<3<<'\n';
		cout<<a<<' '<<b<<' '<<c<<'\n';
	}
  return 0;
}