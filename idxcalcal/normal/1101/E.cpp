#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef long long ll;
typedef pair<int,int> pii;
int mod;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline void Add(int&a,int b){a=add(a,b);}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline void Dec(int&a,int b){a=dec(a,b);}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int N=5e5+5;
int n;
char op;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	int mx1=0,mx2=0;
	for(ri i=1;i<=n;++i){
		op=gc();
		while(op!='+'&&op!='?')op=gc();
		if(op=='+'){
			int a=read(),b=read();
			if(a>b)swap(a,b);
			mx1=max(mx1,a);
			mx2=max(mx2,b);
		}
		else{
			int a=read(),b=read();
			if(a>b)swap(a,b);
			puts(a>=mx1&&b>=mx2?"YES":"NO");
		}
	}
	return 0;
}