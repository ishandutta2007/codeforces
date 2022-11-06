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
const int N=2e5+5;
int n,dep[N];
namespace lct{
	#define lc (son[p][0])
	#define rc (son[p][1])
	int vl[N],son[N][2],fa[N];
	inline bool which(int x){return x==son[fa[x]][1];}
	inline bool isroot(int x){return !fa[x]||(son[fa[x]][0]!=x&&son[fa[x]][1]!=x);}
	inline void rotate(int x){
		int y=fa[x],z=fa[y],t=which(x);
		if(!isroot(y))son[z][which(y)]=x;
		fa[y]=x,fa[x]=z,son[y][t]=son[x][t^1],son[x][t^1]=y;
		if(son[y][t])fa[son[y][t]]=y;
		vl[x]=vl[y];
	}
	inline void splay(int x){
		while(!isroot(x)){
			if(!isroot(fa[x]))rotate(which(x)^which(fa[x])?x:fa[x]);
			rotate(x);
		}
	}
	inline int access(int x,int lm){
		int y,res=dep[x];
		for(y=0;x;x=fa[y=x]){
			splay(x);
			if(vl[x]+2*dep[x]>lm)break;
			(son[x][1])&&(vl[son[x][1]]=vl[x]);
			son[x][1]=y;
		}
		y&&(vl[y]=lm-2*dep[x]);
		return res+lm-2*dep[x];
	}
	#undef lc
	#undef rc
}
struct Node{
	int a,b,id;
	friend inline bool operator<(Node a,Node b){return a.b!=b.b?a.b<b.b:a.a<b.a;}
}qry[N];
int m,ans[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read();
	for(ri i=1;i<=n;++i){
		lct::fa[i]=read();
		lct::vl[i]=-1e9;
		dep[i]=dep[lct::fa[i]]+1;
	}
	for(ri i=1;i<=m;++i)qry[i].a=read(),qry[i].b=read()+dep[qry[i].a],qry[i].id=i;
	sort(qry+1,qry+m+1);
	for(ri i=1;i<=m;++i)ans[qry[i].id]=lct::access(qry[i].a,qry[i].b);
	for(ri i=1;i<=m;++i)cout<<ans[i]<<' ';
	return 0;
}