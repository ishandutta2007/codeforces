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
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
namespace modular{
	const int mod=1e9+7;
	inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
	inline void Add(int&a,int b){a=add(a,b);}
	inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
	inline void Dec(int&a,int b){a=dec(a,b);}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
}
using namespace modular;
int x,y,res=0;
vector<int>divv;
void dfs(int ps,int mt,int coe){
	if(~coe)Add(res,ksm(2,y/mt-1));
	else Dec(res,ksm(2,y/mt-1));
	for(ri i=ps;~i;--i)dfs(i-1,mt*divv[i],-coe);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	x=read(),y=read();
	if(y%x)return cout<<0,0;
	y/=x;
	int t=y;
	for(ri a,i=2,len=sqrt(y);i<=len&&t!=1;++i){
		if(t!=t/i*i)continue;
		while(t==t/i*i)t/=i;
		divv.pb(i);
	}
	if(t^1)divv.pb(t);
	dfs(divv.size()-1,1,1);
	cout<<res;
	return 0;
}