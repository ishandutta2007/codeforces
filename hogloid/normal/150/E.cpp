#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;

int n,l,r;
vector<pi> g2[100005],g[100005];
int cut[100005],size[100005];

int bcost,root,all;
bool ok;
int startP,endP;
struct segtree{
	pi val[400005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i].fr=-INF;
	}
	void set(int k,int a,int who){
		k+=n-1;
		val[k]=max(val[k],mp(a,who));
		while(k>0){
			k=(k-1)/2;
			val[k]=max(val[k*2+1],val[k*2+2]);
			if(val[k].fr!=a) return;
		}
	}
	pi query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return mp(-INF,-INF);
		int md=(l+r)>>1;
		return max(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};
segtree seg;

void dfs2(int v,int p,int sum,int dep){
	int L=l-dep,R=r-dep;
	pi maxi=seg.query(L,R,0,0,seg.n);
	if(maxi.fr+sum>=0){
		
		startP=v;
		endP=maxi.sc;
		ok=true;
	}

	REP(i,g[v].size()){
		pi& e=g[v][i];
		if(cut[e.fr] || e.fr==p) continue;
		
		dfs2(e.fr,v,sum+e.sc,dep+1);
	}
}
void dfs3(int v,int p,int sum,int dep){
	seg.set(dep,sum,v);

	REP(i,g[v].size()){
		pi& e=g[v][i];
		if(cut[e.fr] || e.fr==p) continue;
		
		dfs3(e.fr,v,sum+e.sc,dep+1);
	}
}

int getsize(int v,int p){
	size[v]=1;
	REP(i,g[v].size()){
		pi& e=g[v][i];
		if(cut[e.fr] || e.fr==p) continue;
		size[v]+=getsize(e.fr,v);
	}
	return size[v];
}

void getroot(int v,int p){
	int maxi=all-size[v];
	REP(i,g[v].size()){
		int to=g[v][i].fr;
		if(cut[to] || to==p) continue;
		maxi=max(maxi,size[to]);
		getroot(to,v);
	}
	if(maxi<bcost){
		bcost=maxi;
		root=v;
	}
}


void dfs(int v){
	getsize(v,-1);
	all=size[v];
	if(all<l+1) return;
	bcost=INF;
	getroot(v,-1);


	v=root;
	
	seg.init(all+1);
	
	seg.set(0,0,v);

	REP(i,g[v].size()){
		pi& e=g[v][i];
		if(cut[e.fr]) continue;
		dfs2(e.fr,v,e.sc,1);

		dfs3(e.fr,v,e.sc,1);
		if(ok) return;
	}
	
	cut[v]=1;
	REP(i,g[v].size()){
		pi& e=g[v][i];
		if(cut[e.fr]) continue;
		dfs(e.fr);
		if(ok) return;
	}
}


int zip[100005];
	

int main(){
	scanf("%d%d%d",&n,&l,&r);
	++r;
	REP(i,n-1){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
		g2[a].pb(mp(b,c));
		g2[b].pb(mp(a,c));
		zip[i]=c;
	}
	sort(zip,zip+n-1);

	int lb=-1,ub=n-1;
	while(ub-lb>1){
		int md2=(lb+ub)>>1,md=zip[md2];

		REP(i,n){
			g[i].clear();
			REP(j,g2[i].size()){
				pi& e=g2[i][j];
				g[i].pb(mp(e.fr,e.sc>=md?1:-1));
			}
		}
		seg.init(n);
		memset(cut,0,sizeof(cut));
		ok=false;
		dfs(0);
		if(ok) lb=md2;
		else ub=md2;
	}

	printf("%d %d\n",startP+1,endP+1);

	return 0;
}