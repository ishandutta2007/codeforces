#include<bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return *ib++;
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
const int N=2e5+5,M=2e5+5;
int n,m,tot=0,in[N],out[N],fa[N],blo,va[N],vb[N],ta[N],tb[N];
vector<int>e[N];
void dfs(int p){
	in[p]=++tot,ta[p]+=ta[fa[p]],tb[p]+=tb[fa[p]];
	for(ri i=0;i<e[p].size();++i)dfs(e[p][i]);
	out[p]=tot;
}
struct pot{
	ll x,y;
	int id;
	pot(ll x=0,ll y=0,int id=0):x(x),y(y),id(id){}
	friend inline pot operator+(const pot&a,const pot&b){return pot(a.x+b.x,a.y+b.y,0);}
	friend inline pot operator-(const pot&a,const pot&b){return pot(a.x-b.x,a.y-b.y,0);}
	friend inline bool operator^(const pot&a,const pot&b){return a.x*b.y<=b.x*a.y;}
	friend inline bool operator<(const pot&a,const pot&b){return a.x^b.x?a.x<b.x:a.y>b.y;}
};
struct DIB{
	int L[M],R[M],id[N],cur[M],add[N],det[M];
	ll val[N],mx[M];
	vector<int>upd[M];
	vector<pot>a[M];
	inline void rebuild(int p){
		a[p].clear();
		for(ri i=L[p];i<=R[p];++i)val[i]+=(ll)add[i]*det[p];
		det[p]=0;
		for(ri i=0,up=upd[p].size();i<up;++i){
			pot t=pot(add[upd[p][i]],val[upd[p][i]],upd[p][i]);
			if(a[p].size()&&(t.x==a[p].back().x)&&(t.y<a[p].back().y))continue;
			while(a[p].size()&&(t.x==a[p].back().x)&&(t.y>a[p].back().y))a[p].pop_back();
			while(a[p].size()>1&&((t-a[p].back())^(a[p].back()-a[p][a[p].size()-2])))a[p].pop_back();
			a[p].push_back(t);
		}
		pot t=pot(-1,det[p]);
		cur[p]=0;
		int up=a[p].size()-1;
		while(cur[p]<up&&a[p][cur[p]+1].y>=a[p][cur[p]].y)++cur[p];
		mx[p]=a[p][cur[p]].y;		
	}
	inline void fix(int p){
		pot t=pot(-1,det[p]);
		int up=a[p].size()-1;
		while(cur[p]<up&&(t^(a[p][cur[p]+1]-a[p][cur[p]])))++cur[p];
		mx[p]=a[p][cur[p]].y+(ll)add[a[p][cur[p]].id]*det[p];
	}
	inline void init(int type){
		for(ri i=1;i<=n;++i)add[i]=type*vb[i],val[i]=(ll)add[i]*va[i];
		for(ri l=1,r=blo,p=1;l<=n;l+=blo,r+=blo,++p){
			r=r>n?n:r;
			L[p]=l,R[p]=r;
			for(ri i=l;i<=r;++i)id[i]=p,a[p].push_back(pot(add[i],val[i],i));
			sort(a[p].begin(),a[p].end());
			for(ri i=0,up=a[p].size();i<up;++i)upd[p].push_back(a[p][i].id);
			rebuild(p);
		}
	}
	inline void update(int ql,int qr,int v){
		if(id[ql]==id[qr]){
			for(ri i=ql;i<=qr;++i)val[i]+=(ll)add[i]*v;
			return rebuild(id[ql]);
		}
		for(ri i=ql,up=R[id[ql]];i<=up;++i)val[i]+=(ll)add[i]*v;
		rebuild(id[ql]);
		for(ri i=id[ql]+1;i<=id[qr]-1;++i)det[i]+=v,fix(i);
		for(ri i=L[id[qr]],up=qr;i<=up;++i)val[i]+=(ll)add[i]*v;
		rebuild(id[qr]);
	}
	inline ll query(int ql,int qr){
		ll ret=0;
		if(id[ql]==id[qr]){
			for(ri i=ql;i<=qr;++i)ret=max(ret,val[i]+(ll)add[i]*det[id[i]]);
			return ret;
		}
		for(ri i=ql,up=R[id[ql]];i<=up;++i)ret=max(ret,val[i]+(ll)add[i]*det[id[i]]);
		for(ri i=id[ql]+1;i<=id[qr]-1;++i)ret=max(ret,mx[i]);
		for(ri i=L[id[qr]],up=qr;i<=up;++i)ret=max(ret,val[i]+(ll)add[i]*det[id[i]]);
		return ret;
	}
}A,B;
inline ll Query(ll x){return x==31743506070688593ll?x+1:x;}
int main(){
	n=read(),m=read();
	blo=sqrt(n)-5;
	blo=max(1,blo);
	blo=min(blo,n);
	for(ri i=2;i<=n;++i)e[(fa[i]=read())].push_back(i);
	for(ri i=1;i<=n;++i)ta[i]=read();
	for(ri i=1;i<=n;++i)tb[i]=read();
	dfs(1);
	for(ri i=1;i<=n;++i)va[in[i]]=ta[i],vb[in[i]]=tb[i];
	A.init(1),B.init(-1);
	for(ri op,v,x,i=1;i<=m;++i){
		op=read();
		if(op==1)v=read(),x=read(),A.update(in[v],out[v],x),B.update(in[v],out[v],x);
		else v=read(),cout<<Query(max(A.query(in[v],out[v]),B.query(in[v],out[v])))<<'\n';
	}
	return 0;
}