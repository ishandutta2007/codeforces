#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int artf,fu;
// v has to be the other node :(
struct E{
	int u,v;
};

// IF DOING QUERIES THEN READ ALL OF THIS
// ng contains a block-cut tree that has edges with old labels, so you have to use par[u] when using it 
// should work with self-loops, multi edges and multiple components
// high constant & memory usage, but O(n+m)
// use isart[par[u]] for arts, to get all components u belongs to, use ng[par[u]]
// parent component of each art is the last entry in ng[par[u]]
// use them if updating nodes, and add 1 node above lcm when querying
// (only when the lcm is a component), careful that if root is an art, 
// you shouldn't use its parent component (it doesn't have any)
// there can be n-2 arts, and n-1 comps at the same time
struct BCT{
	int n,c=1;
	vector<vector<E>>g,inside;
	vector<vector<int>>ng;
	vector<int>par,low,dpt,vis,isart;
	BCT(int n):n(n),g(n),inside(2*n),ng(2*n),par(n,-1),low(n),dpt(n),vis(n),isart(2*n){}
	void ae(E e){E oe=e;swap(oe.u,oe.v);
		g[e.u].push_back(e);
		g[e.v].push_back(oe);
	}
	void nae(int u,int v){
		ng[u].push_back(v);
		ng[v].push_back(u);
	}
	void dfs2(int u,int f,int cc){
		vis[u]=true;
		if(~par[u])nae(par[u],cc);
		else par[u]=cc;
		for(E e:g[u])if(e.v!=f&&!vis[e.v]){
			inside[cc].push_back(e);
			dfs2(e.v,f,cc);
		}
	}
	int dfs(int u,int p,int d){
		low[u]=dpt[u]=d;
		int pv=-1;
		for(E e:g[u])if(e.v!=p){
			if(dpt[e.v])low[u]=min(low[u],dpt[e.v]);
			else{
				int lw=dfs(e.v,u,d+1);
				low[u]=min(low[u],lw);
				if(lw>=d&&(d!=1||~pv)){
					if(par[u]==-1){
						isart[par[u]=(u?c++:0)]=true;
						if(d==1){dfs2(pv,u,c);nae(par[u],c++);}
					}
					dfs2(e.v,u,c);nae(par[u],c++);
				}
				pv=e.v;
			}
		}
		if(d==1&&par[u]==-1)dfs2(u,-1,u?c++:0);
		return low[u];
	}
	void calc(){for(int i=0;i<n;++i)if(!vis[i])dfs(i,i,1);}
};

// seg tree for one operation
template<class O>
struct SegmentTree{
	using T=typename O::T;
	int n;vector<T>tr,lz;
	SegmentTree(vector<T>a):n(1<<int(1+log2(a.size()))),tr(2*n,O::D),lz(2*n,O::DL){
		copy(a.begin(),a.end(),tr.begin()+n);
		for(int i=n-1;i>0;--i)tr[i]=O::uni(tr[2*i],tr[2*i+1]);
	}
	void applylazy(int u,int lb,int rb){
		if(lz[u]!=O::DL){
			tr[u]=O::rv(tr[u],lz[u],lb,rb);
			O::upd(lz[2*u],lz[u]);
			O::upd(lz[2*u+1],lz[u]);
			lz[u]=O::DL;
		}
	}
	T query(int l,int r){return query(l,r,0,n,1);}
	T query(int l,int r,int lb,int rb,int u){
		if(rb<=l||r<=lb)return O::D;
		if(l<=lb&&rb<=r)return O::rv(tr[u],lz[u],lb,rb);
		applylazy(u,lb,rb);
		int m=(lb+rb)/2;
		return O::uni(query(l,r,lb,m,2*u),query(l,r,m,rb,2*u+1));
	}
	T update(int l,int r,T x){return update(l,r,0,n,1,x);}
	T update(int l,int r,int lb,int rb,int u,T x){
		if(rb<=l||r<=lb)return O::rv(tr[u],lz[u],lb,rb);
		if(l<=lb&&rb<=r)return O::rv(tr[u],O::upd(lz[u],x),lb,rb);
		applylazy(u,lb,rb);
		int m=(lb+rb)/2;
		return tr[u]=O::uni(update(l,r,lb,m,2*u,x),update(l,r,m,rb,2*u+1,x));
	}
};

struct min_set{
	typedef int T;
	static const T D=numeric_limits<T>::max(),DL=0;
	static T rv(T val,T lz,int lb,int rb){return lz?lz:val;}
	static T upd(T&a,T b){return a=b;}
	static T uni(T a,T b){return min(a,b);}
};
const int min_set::D,min_set::DL;


// you have to set values to nodes/edges manually
// (can't init st trivialy since order is changed)
// seg trees go from top to bottom, always following the first child
template<bool E,class O>
struct HLD{
	using T=typename O::T;
	int n,tim=0;
	vector<vector<int>>g;
	// parent, size of subtree, depth, position of u in memory, root of segtree
	vector<int>p,sz,d,pos,rt;
	SegmentTree<O>st;
	HLD(vector<vector<int>>&g):n(g.size()),g(g),p(n),sz(n,1),d(n),pos(n),rt(n),
														st(vector<T>(n)){dfsz(0);dfshld(0);} // c?
	void dfsz(int u){
		g[u].erase(remove(g[u].begin(),g[u].end(),p[u]),g[u].end());
		for(auto&v:g[u]){
			p[v]=u,d[v]=d[u]+1;
			dfsz(v);
			sz[u]+=sz[v];
			if(sz[v]>sz[g[u][0]])swap(v,g[u][0]);
		}
	}
	void dfshld(int u){
		pos[u]=tim++;
		for(auto v:g[u]){
			rt[v]=(v==g[u][0]?rt[u]:v);
			dfshld(v);
		}
	}
	template<class X>
	void walk(int u,int v,X op){
		for(;rt[u]!=rt[v];u=p[rt[u]]){
			if(d[rt[u]]<d[rt[v]])swap(u,v);
			op(pos[rt[u]],pos[u]+1);
		}
		if(d[u]<d[v])swap(u,v);
		op(pos[v]+E,pos[u]+1);
		if(v&&(d[v]&1)==artf)fu=p[v];
		else fu=-1;
	}
	void update(int u,int v,T val){walk(u,v,[&](int l,int r){st.update(l,r,val);});}
	T query(int u,int v){
		T res=O::D;
		walk(u,v,[&](int l,int r){res=min(res,st.query(l,r));});
		return res;
	}
	T querytree(int u){return st.query(pos[u]+E,pos[u]+sz[u]+1);}
};



void ProGamerMove(){
	int n,m,q;cin>>n>>m>>q;
	vector<int>val(n);
	for(int i=0;i<n;++i)cin>>val[i];
	BCT bct(n);
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;--u;--v;
		bct.ae({u,v});
	}
	bct.calc();
	int nn=bct.c;
//	cerr<<nn<<endl;
//	for(int i=0;i<n;++i)cerr<<bct.par[i]<<endl;
//	vector<vector<int>>g=bct.ng;
//	for(int u=0;u<nn;++u)
//		for(int v:g[u])
//			cerr<<u<<" "<<v<<endl;
//	return;
	artf=bct.isart[bct.par[0]];
	vector<map<int,int>>pq(bct.c);
	for(int u=0;u<n;++u){
//		cerr<<u<<" "<<bct.par[u]<<" "<<bct.c<<endl;
		int pu=bct.par[u];
		if(u&&bct.isart[pu])++pq[bct.ng[pu].back()][val[u]];
		++pq[pu][val[u]];
	}
	HLD<0,min_set>hld(bct.ng);
	for(int u=0;u<bct.c;++u)hld.update(u,u,pq[u].begin()->first);
	while(q--){
		char t;cin>>t;
		if(t=='C'){
			int u,w;cin>>u>>w;--u;
			int pu=bct.par[u];
			if(!--pq[pu][val[u]])pq[pu].erase(pq[pu].find(val[u]));
			++pq[pu][w];
			hld.update(pu,pu,pq[pu].begin()->first);
			if(u&&bct.isart[pu]){
				int pv=bct.ng[pu].back();
				if(!--pq[pv][val[u]])pq[pv].erase(pq[pv].find(val[u]));
				++pq[pv][w];
				hld.update(pv,pv,pq[pv].begin()->first);
			}
			val[u]=w;
		}else{
			int u,v;cin>>u>>v;--u;--v;
			if(u==v){cout<<val[u]<<"\n";continue;}
			int res=hld.query(bct.par[u],bct.par[v]);
//			cerr<<res<<" "<<fu<<endl;
			if(~fu)res=min(res,pq[fu].begin()->first);
			cout<<res<<"\n";
		}
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	//cin>>tc;
	while(tc--)ProGamerMove();
}