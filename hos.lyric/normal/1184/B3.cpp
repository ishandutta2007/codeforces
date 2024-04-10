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

const int inf=LLONG_MAX/3;

template<class d>
struct maxflow{
	struct E{
		int to,rev;
		d cap;
	};
	vvc<E> g;
	vi itr,lv;
	maxflow(int n):g(n),itr(n),lv(n){}
	void ae(int s,int t,d c){
		g[s].pb({t,(int)g[t].size(),c});
		g[t].pb({s,(int)g[s].size()-1,0});
	}
	void bfs(int s){
		fill(all(lv),-1);
		lv[s]=0;
		queue<int> q;
		q.push(s);
		while(q.size()){
			int v=q.front();q.pop();
			for(auto e:g[v])if(e.cap>0&&lv[e.to]==-1){
				lv[e.to]=lv[v]+1;
				q.push(e.to);
			}
		}
	}
	d dfs(int v,int t,d f){
		if(v==t)return f;
		d res=0;
		for(int&i=itr[v];i<(int)g[v].size();i++){
			E& e=g[v][i];
			if(e.cap>0&&lv[e.to]==lv[v]+1){
				d a=dfs(e.to,t,min(f,e.cap));
				if(a>0){
					e.cap-=a;
					g[e.to][e.rev].cap+=a;
					res+=a;
					f-=a;
					if(f<=0)break;
				}
			}
		}
		return res;
	}
	d calc(int s,int t){
		d f=0;
		while(1){
			bfs(s);
			if(lv[t]==-1)
				return f;
			fill(all(itr),0);
			f+=dfs(s,t,1e9);
		}
	}
};


void sub(vi pro,int k){
	int n=pro.size();
	vi iso(n,1);
	vc<pi> es;
	rep(_,k){
		int a,b;cin>>a>>b;
		a--;b--;
		es.eb(a,b);
		iso[a]=0;
		iso[b]=0;
	}
	int base=0;
	vi idx;
	rep(i,n)if(iso[i]){
		base+=max(int(0),pro[i]);
	}else{
		idx.pb(i);
	}
	
	int s=idx.size();
	maxflow<int> mcf(1+s+1);
	rep(i,s){
		if(pro[idx[i]]>0){
			base+=pro[idx[i]];
			mcf.ae(0,1+i,pro[idx[i]]);
		}else{
			mcf.ae(1+i,1+s,-pro[idx[i]]);
		}
	}
	for(auto e:es){
		int a=lower_bound(all(idx),e.a)-idx.bg;
		int b=lower_bound(all(idx),e.b)-idx.bg;
		mcf.ae(1+a,1+b,inf);
	}
	
	cout<<base-mcf.calc(0,1+s)<<endl;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,m;cin>>n>>m;
	vvc<int> dist(n,vi(n,inf));
	rep(i,n)dist[i][i]=0;
	rep(_,m){
		int a,b;cin>>a>>b;
		a--;b--;
		dist[a][b]=1;
		dist[b][a]=1;
	}
	rep(k,n)rep(i,n)rep(j,n)
		chmin(dist[i][j],dist[i][k]+dist[k][j]);
	
	int s,b,k;cin>>s>>b>>k;
	vc<tuple<int,int,int,int>> xafp;
	rep(i,s){
		int x,a,f,p;cin>>x>>a>>f>>p;
		x--;
		xafp.eb(x,a,f,p);
	}
	vc<tuple<int,int,int>> xdg;
	rep(i,b){
		int x,d,g;cin>>x>>d>>g;
		x--;
		xdg.eb(x,d,g);
	}
	vc<pi> ord;
	rep(i,s)
		ord.eb(get<1>(xafp[i]),b+i);
	rep(i,b)
		ord.eb(get<1>(xdg[i]),i);
	vi pro(s);
	vi mxg(n,-inf);
	sort(all(ord));
	for(auto kv:ord){
		int i=kv.b;
		if(i<b){
			chmax(mxg[get<0>(xdg[i])],get<2>(xdg[i]));
		}else{
			i-=b;
			int x,a,f,p;
			tie(x,a,f,p)=xafp[i];
			int mx=-inf;
			rep(j,n)if(dist[x][j]<=f)
				chmax(mx,mxg[j]);
			pro[i]=mx-p;
		}
	}
	sub(pro,k);
}