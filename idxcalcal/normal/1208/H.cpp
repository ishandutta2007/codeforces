#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
typedef pair<int,int> pii;
const int N=1e6+5;
int rt[N],n;
inline int rnd(){return rand()|(rand()<<15);}
namespace bst{
	#define lc (son[p][0])
	#define rc (son[p][1])
	int son[N][2],siz[N],vl[N],rd[N];
	int stk[N],top=0,tot=0;
	inline int newidx(){return ++tot;}
	inline int newnode(int v){
		int p=newidx();
		lc=rc=0,siz[p]=1,vl[p]=v,rd[p]=rnd();
		return p;
	}
	inline int pushup(int p){siz[p]=(!p?0:siz[lc]+1+siz[rc]);}
	inline int merge(int a,int b){
		if(!a||!b)return a|b;
		if(rd[a]<rd[b])return son[a][1]=merge(son[a][1],b),pushup(a),a;
		return son[b][0]=merge(a,son[b][0]),pushup(b),b;
	}
	inline pii split(int p,int k){
		if(!p)return pii(0,0);
		pii res;
		if(siz[lc]>=k)return res=split(lc,k),lc=res.se,pushup(p),pii(res.fi,p);
		return res=split(rc,k-siz[lc]-1),rc=res.fi,pushup(p),pii(p,res.se);
	}
	inline int rank(int p,int v){
		if(!p)return 0;
		if(vl[p]>v)return rank(lc,v);
		return siz[lc]+1+rank(rc,v);
	}
	inline void insert(int&rt,int v){
		int rk=rank(rt,v);
		pii x=split(rt,rk);
		rt=merge(merge(x.fi,newnode(v)),x.se);
	}
	inline void delet(int&rt,int v){
		int rk=rank(rt,v);
		pii x=split(rt,rk-1),y=split(x.se,1);
		rt=merge(x.fi,y.se),y.fi&&(stk[++top]=y.fi);
	}
	#undef lc
	#undef rc
}
struct F{
	int l,r;
	F(int l=0,int r=0):l(l),r(r){}
	friend inline F operator+(F a,F b){return F(min(max(a.l,b.l),a.r),min(max(a.l,b.r),a.r));}
};
const int inf=1e9;
int K,tg[N];
int siz[N],hson[N],dep[N],top[N],fa[N],num[N],pred[N],bot[N],col[N],tot=0;
vector<int>e[N];
void dfs1(int p){
	siz[p]=1;
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==fa[p])continue;
		fa[v]=p,dep[v]=dep[p]+1,dfs1(v),siz[p]+=siz[v];
		if(siz[v]>siz[hson[p]])hson[p]=v;
	}
}
void dfs2(int p,int tp){
	top[p]=tp,bot[tp]=p,pred[num[p]=++tot]=p;
	if(!hson[p])return;
	dfs2(hson[p],tp);
	for(ri i=0,v;i<e[p].size();++i)if((v=e[p][i])!=fa[p]&&v!=hson[p])dfs2(v,v);
}
namespace sgt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define mid (l+r>>1)
	F vl[N<<2];
	inline void pushup(int p){vl[p]=vl[lc]+vl[rc];}
	inline F query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return vl[p];
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(ql>mid)return query(rc,mid+1,r,ql,qr);
		return query(lc,l,mid,ql,qr)+query(rc,mid+1,r,ql,qr);
	}
	inline bool check(int p,int k,int dt){
		int R=bst::rank(rt[p],k)+dt,B=bst::siz[rt[p]]+1-R;
		return B-R<k;
	}
	inline void fix(int p,int&k,int dt){
		while(check(p,k-1,dt))--k;
		while(!check(p,k,dt))++k;
	}
	inline void getval(int p,int k){
		if(col[k]==1)vl[p]=F(inf,inf);
		else if(!col[k])vl[p]=F(-inf,-inf);
		else{
			fix(k,vl[p].l,1);
			fix(k,vl[p].r,0);
		}
	}
	inline void build(int p,int l,int r){
		if(l==r){
			int k=pred[l];
			getval(p,k);
			if(k==top[k]&&fa[k]){
				if(bot[k]==k)bst::insert(rt[fa[k]],tg[k]=vl[p].l);
				else bst::insert(rt[fa[k]],tg[k]=(vl[p]+query(1,1,n,l+1,num[bot[k]])).l);
			}
			return;
		}
		build(rc,mid+1,r),build(lc,l,mid);
		pushup(p);
	}
	inline void update(int p,int l,int r,int k){
		if(l==r)return getval(p,pred[l]);
		k<=mid?update(lc,l,mid,k):update(rc,mid+1,r,k);
		pushup(p);
	}
	#undef mid
	#undef lc
	#undef rc
}
inline void change(int p){
	int tp,ftp;
	while(p){
		tp=top[p],ftp=fa[top[p]];
		sgt::update(1,1,n,num[p]);
		if(ftp){
			bst::delet(rt[ftp],tg[tp]);
			bst::insert(rt[ftp],tg[tp]=sgt::query(1,1,n,num[tp],num[bot[tp]]).l);
		}
		p=ftp;
	}
}
int main(){
	srand(time(NULL));
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),K=read();
	for(ri i=1,u,v;i<n;++i){
		u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	for(ri i=1;i<=n;++i)col[i]=read();
	dfs1(1),dfs2(1,1);
	sgt::build(1,1,n);
	for(ri op,x,tt=read();tt;--tt){
		op=read();
		switch(op){
			case 1:{x=read(),cout<<(sgt::query(1,1,n,num[x],num[bot[top[x]]]).l>K)<<'\n';break;}
			case 2:{x=read(),col[x]=read(),change(x);break;}
			case 3:{K=read();break;}
		}
	}
	return 0;
}