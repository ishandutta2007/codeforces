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
typedef vector<int> poly;
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
const int N=3e5+5;
int n,m,col[N];
vector<int>e[N],tp[4];
bool vs[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read();
	for(ri i=1;i<=n;++i)col[i]=-1;
	for(ri u,v,i=1;i<=m;++i){
		u=read(),v=read();
		e[u].pb(v);
		e[v].pb(u);
	}
	for(ri i=0;i<e[1].size();++i)vs[e[1][i]]=1;
	for(ri i=1;i<=n;++i)if(!vs[i])tp[1].pb(i),col[i]=1;
	int ps=-1;
	for(ri i=1;i<=n;++i){
		if(vs[i]){
			ps=i;
			break;
		}
	}
	if(ps==-1)return puts("-1"),0;
	for(ri i=0;i<e[ps].size();++i)if(vs[e[ps][i]])tp[3].pb(e[ps][i]),col[e[ps][i]]=3;
	for(ri i=1;i<=n;++i)if(col[i]==-1)col[i]=2,tp[2].pb(i);
	if(!tp[2].size()||!tp[3].size())return puts("-1"),0;
	if((ll)tp[1].size()*tp[2].size()+(ll)tp[2].size()*tp[3].size()+(ll)tp[3].size()*tp[1].size()!=m)return puts("-1"),0;
	for(ri i=1;i<=n;++i)for(ri j=0;j<e[i].size();++j)if(col[i]==col[e[i][j]])return puts("-1"),0;
	for(ri i=1;i<=n;++i)cout<<col[i]<<' ';
	return 0;
}