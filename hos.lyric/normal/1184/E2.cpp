#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

//KUPC2017J
//AOJDSL1A
//without rank
struct unionfind{
	vi p,s;
	int c;
	unionfind(int n):p(n,-1),s(n,1),c(n){}
	int find(int a){
		return p[a]==-1?a:(p[a]=find(p[a]));
	}
	//set b to a child of a
	bool unite(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return false;
		p[b]=a;
		s[a]+=s[b];
		c--;
		return true;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
};

//KUPC2017I
//HDU 5306 Gorgeous Sequence
template<class N>
struct segbeats{
	vc<N> x;
	int s;
	template<class T>
	segbeats(const vc<T>& a){
		int n=a.size();
		s=1;
		while(s<n)s*=2;
		x.resize(s*2);
		rep(i,n)
			x[s+i]=N(a[i]);
		gnr(i,1,s)
			upd(i);
	}
	void push(int i){
		x[i].push(x[i*2],x[i*2+1]);
	}
	void upd(int i){
		x[i]=N::merge(x[i*2],x[i*2+1]);
	}
	template<class F,class... Args>
	void chr(int l,int r,int i,int b,int e,F f,Args... args){
		if(e<=l||r<=b)
			return;
		if(b<=l&&r<=e&&(x[i].*f)(args...))
			return;
		push(i);
		int m=(l+r)/2;
		chr(l,m,i*2,b,e,f,args...);
		chr(m,r,i*2+1,b,e,f,args...);
		upd(i);
	}
	template<class F,class... Args>
	void ch(int b,int e,F f,Args... args){
		assert(b<e);
		chr(0,s,1,b,e,f,args...);
	}
	//use decltype((declval<N>().*F())()) for old-fashioned judges
	template<class F,class G,class H>
	auto getr(int l,int r,int i,int b,int e,F f,G g,H h){
		if(e<=l||r<=b)
			return h;
		if(b<=l&&r<=e)
			return (x[i].*f)();
		push(i);
		int m=(l+r)/2;
		return g(getr(l,m,i*2,b,e,f,g,h),getr(m,r,i*2+1,b,e,f,g,h));
	}
	template<class F,class G,class H>
	auto get(int b,int e,F f,G g,H h){
		assert(b<e);
		return getr(0,s,1,b,e,f,g,h);
	}
	//return maximum index
	template<class F,class...Args>
	pair<int,N> findr(int i,int l,int r,int b,int e,F f,Args...args){
		if(e<=l||r<=b||!(x[i].*f)(args...))return {b-1,N()};
		if(b<=l&&r<=e&&r-l==1)
			return {l,x[i]};
		push(i);
		int m=(l+r)/2;
		auto a=findr(i*2+1,m,r,b,e,f,args...);
		if(b<=a.a)return a;
		return findr(i*2,l,m,b,e,f,args...);
	}
	template<class F,class...Args>
	pair<int,N> find(int b,int e,F f,Args...args){
		assert(b<e);
		return findr(1,0,s,b,e,f,args...);
	}
};

//usage

const int inf=INT_MAX;

//Range chmin,mn
struct N{
	int lz,mn;
	N(int v=0):lz(inf),mn(v){}
	bool chm(int v){
		chmin(lz,v);
		return true;
	}
	void push(N&x,N&y){
		x.chm(lz);
		y.chm(lz);
		chmin(mn,lz);
		lz=inf;
	}
	static N merge(N x,N y){
		return N(min(x.getm(),y.getm()));
	}
	int getm(){return min(lz,mn);}
};


int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}

//AOJGRL5C
template<class t,class u>
struct sparsetable{
	vvc<t> a;
	u f;
	//d must not be empty
	sparsetable(const vc<t>& d,u ff):f(ff){
		int n=d.size(),h=topbit(n);
		a.resize(h+1);
		a[0]=d;
		rng(j,1,h+1){
			a[j].resize(n-(1<<j)+1);
			rep(i,n-(1<<j)+1)
				a[j][i]=f(a[j-1][i],a[j-1][i+(1<<(j-1))]);
		}
	}
	t get(int b,int e){
		assert(b<e);
		int d=topbit(e-b);
		return f(a[d][b],a[d][e-(1<<d)]);
	}
};

//CF530F
//CodeChef Persistent Oak
//AOJ GRL5C
template<class E>
struct HLD{
	vvc<E> g;
	int n,rt,cnt;
	vi sub,in,out,par,head,dep;
	int dfs1(int v,int p,int d){
		par[v]=p;
		dep[v]=d;
		g[v].erase(remove(all(g[v]),p),g[v].ed);
		for(auto&e:g[v]){
			sub[v]+=dfs1(e,v,d+1);
			if(sub[g[v][0]]<sub[e])
				swap(g[v][0],e);
		}
		return sub[v];
	}
	void dfs2(int v,int h){
		in[v]=cnt++;
		head[v]=h;
		for(int to:g[v])
			dfs2(to,to==g[v][0]?h:to);
		out[v]=cnt;
	}
	HLD(const vvc<E>&gg,int rr):g(gg),n(g.size()),rt(rr),cnt(0),
		sub(n,1),in(n),out(n),par(n,-1),head(n),dep(n){
		dfs1(rt,-1,0);
		dfs2(rt,rt);
	}
	int lca(int a,int b){
		while(head[a]!=head[b]){
			if(dep[head[a]]>dep[head[b]])
				swap(a,b);
			b=par[head[b]];
		}
		if(dep[a]>dep[b])
			swap(a,b);
		return a;
	}
	void slv(vc<tuple<int,int,int,int>> es,vi te){
		int m=es.size();
		vi def(n-1);
		for(auto e:es){
			int c,a,b,i;
			tie(c,a,b,i)=e;
			if(te[i]){
				if(dep[a]<dep[b])swap(a,b);
				def[in[a]-1]=c;
			}
		}
		const int V=1000000000;
		auto imax=[](int x,int y){return max(x,y);};
		sparsetable<int,decltype(imax)> st(def,imax);
		segbeats<N> seg(vi(n-1,V));
		vi ans(m,0);
		for(auto e:es){
			int c,a,b,i;
			tie(c,a,b,i)=e;
			if(!te[i]){
				dmp(c);
				int l=lca(a,b);
				rep(_,2){
					int x=a;
					while(1){
						int h=head[x];
						int s,t;
						if(h==head[l]){
							s=in[l],t=in[x];
						}else{
							s=in[h]-1,t=in[x];
						}
						if(s<t){
							chmax(ans[i],st.get(s,t));
							seg.ch(s,t,&N::chm,c);
						}
						if(h==head[l])break;
						x=par[h];
					}
					swap(a,b);
				}
			}
		}
		for(auto e:es){
			int c,a,b,i;
			tie(c,a,b,i)=e;
			if(te[i]){
				if(dep[a]<dep[b])swap(a,b);
				ans[i]=seg.get(in[a]-1,in[a],&N::getm,[](int p,int q){return min(p,q);},V);
			}
		}
		rep(i,m)if(!te[i])
			cout<<ans[i]<<"\n";
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	vc<tuple<int,int,int,int>> es;
	rep(i,m){
		int a,b,c;cin>>a>>b>>c;
		a--;b--;
		es.eb(c,a,b,i);
	}
	sort(all(es));
	unionfind uf(n);
	vi te(m);
	vvc<int> g(n);
	for(auto e:es){
		int c,a,b,i;
		tie(c,a,b,i)=e;
		if(!uf.same(a,b)){
			uf.unite(a,b);
			g[a].pb(b);
			g[b].pb(a);
			te[i]=1;
		}
	}
	
	HLD<int> hld(g,0);
	hld.slv(es,te);
}