#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define pb push_back
#define rsz resize
#define sz(x) (int)(x).size()
#define lb lower_bound
#define rb upper_bound
#define all(x) begin(x),end(x)
using namespace std;
using namespace __gnu_pbds;
template<class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int Mod=20030112,Bas=('l'-'a')^('d'-'a')^('x'-'a');
inline int add1(int a,int b){return (a+=b)<Mod?a:a-Mod;}
inline int mul1(int a,int b){return (ll)a*b%Mod;}
inline int dec1(int a,int b){return (a-=b)<0?a+Mod:a;}
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int fix(const int&x){return (x%mod+mod)%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
inline int sgn(int x){return (x>0)-(x<0);}
const int N_=1e5+5;
vector<pii>e_[N_];
const int N=100505,M=2e7+5;
int rt[N],hsh[N],hshh[N],pw[N],n,m,dis[N],pre[N],s,t,All=0;
bool vis[N];
inline void rdg3(int m){for(ri i=1,u,v,w;i<=m;++i)u=read(),v=read(),w=read()+1,e_[u].pb(pii(v,w)),e_[v].pb(pii(u,w)),All=max(All,w);}
namespace sgt{
	#define lc (son[p][0])
	#define rc (son[p][1])
	#define mid (l+r>>1)
	int tot=1,son[M][2],siz[M],sum[M],len[M];
	inline void pushup(int p,int l,int r){
		siz[p]=siz[lc]+siz[rc];
		sum[p]=add1(mul1(sum[lc],hsh[r-mid]),sum[rc]);
		len[p]=siz[lc]==mid-l+1?siz[lc]+len[rc]:len[lc];
	}
	inline void update(int&p,int o,int l,int r,int k){
		p=++tot,lc=son[o][0],rc=son[o][1];
		if(l==r){siz[p]=len[p]=1,sum[p]=l;return;}
		k<=mid?update(lc,lc,l,mid,k):update(rc,rc,mid+1,r,k);
		pushup(p,l,r);
	}
	inline pii query(int p,int l,int r,int ql,int qr){
		if(!p)return pii(0,0);
		if(ql<=l&&r<=qr)return pii(len[p],siz[p]==r-l+1);
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(ql>mid)return query(rc,mid+1,r,ql,qr);
		pii res1=query(lc,l,mid,ql,qr),res2;
		if(!res1.se)return res1;
		res2=query(rc,mid+1,r,ql,qr);
		return pii(res1.fi+res2.fi,res2.se);
	}
	inline void modify(int&p,int o,int l,int r,int ql,int qr){
		if(!p)return;
		if(ql<=l&&r<=qr){p=0;return;}
		p=++tot,lc=son[o][0],rc=son[o][1];
		if(qr<=mid)modify(lc,lc,l,mid,ql,qr);
		else if(ql>mid)modify(rc,rc,mid+1,r,ql,qr);
		else modify(lc,lc,l,mid,ql,qr),modify(rc,rc,mid+1,r,ql,qr);
		pushup(p,l,r);
	}
	inline int cmp(int a,int b,int l,int r){
		if(l==r)return sgn(siz[a]-siz[b]);
		if(sum[son[a][1]]==sum[son[b][1]])return cmp(son[a][0],son[b][0],l,mid);
		return cmp(son[a][1],son[b][1],mid+1,r);
	}
	inline int qsum(int p,int l,int r){
		if(!p)return 0;
		if(l==r)return pw[l-1];
		return add(qsum(lc,l,mid),qsum(rc,mid+1,r));
	}
	#undef lc
	#undef rc
	#undef mid
}
struct Node{
	int p;
	Node(int p=0,int v=0):p(p){}
	friend inline bool operator<(const Node&a,const Node&b){
		int vl=sgt::cmp(rt[a.p],rt[b.p],1,All);
		return vl?vl<0:a.p<b.p;
	}
};
set<Node>q;
void dijkstra(){
	rt[s]=1;
	q.insert(Node(s));
	while(q.size()){
		int x=q.begin()->p;
		q.erase(q.begin());
		if(vis[x])continue;
		vis[x]=1;
		for(ri i=0,v,w;i<e_[x].size();++i){
			v=e_[x][i].fi,w=e_[x][i].se;
			if(vis[v])continue;
			rt[n+1]=rt[x];
			int len=sgt::query(rt[x],1,All,w,All).fi;
			if(len)sgt::modify(rt[n+1],rt[n+1],1,All,w,w+len-1);
			sgt::update(rt[n+1],rt[n+1],1,All,w+len);
			if(!rt[v]||(Node(n+1)<Node(v))){
				if(rt[v])q.erase(Node(v,rt[v]));
				rt[v]=rt[n+1];
				pre[v]=x;
				q.insert(Node(v,rt[v]));
			}
		}
	}
	if(!rt[t])puts("-1"),exit(0);
	cout<<sgt::qsum(rt[t],1,All)<<'\n';
	vector<int>print;
	for(ri i=t;i;i=pre[i])print.push_back(i);
	cout<<print.size()<<'\n';
	for(ri i=print.size()-1;~i;--i)cout<<print[i]<<' ';
	puts("");
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	pw[0]=1,hsh[0]=1;
	n=read(),m=read();
	rdg3(m);
	All+=100;
	for(ri i=1;i<=All;++i)pw[i]=add(pw[i-1],pw[i-1]),hsh[i]=mul1(hsh[i-1],Bas);
	s=read(),t=read();
	dijkstra(); 
	return 0;
}