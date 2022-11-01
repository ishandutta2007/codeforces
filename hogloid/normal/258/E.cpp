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
struct segtree{
	int n,n2;
	int val[400005],mini[400005],lazy[400005];
	void init(int n_){
		n2=n_;
		n=1;
		while(n<n_) n<<=1;
		REP(i,n_){
			mini[i+n-1]=0;
			val[i+n-1]=1;
		}
		for(int i=n-2;i>=0;--i){
			mini[i]=0;
			val[i]=val[i*2+1]+val[i*2+2];
		}
	}
	void add(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			lazy[i]+=v;
			mini[i]+=v;
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		if(lazy[i]){
			lazy[i*2+1]+=lazy[i];
			mini[i*2+1]+=lazy[i];
			lazy[i*2+2]+=lazy[i];
			mini[i*2+2]+=lazy[i];
			lazy[i]=0;
		}
		add(a,b,i*2+1,l,md,v);
		add(a,b,i*2+2,md,r,v);
		mini[i]=min(mini[i*2+1],mini[i*2+2]);
		val[i]=0;
		if(mini[i]==mini[i*2+1]) val[i]+=val[i*2+1];
		if(mini[i]==mini[i*2+2]) val[i]+=val[i*2+2];
	}
	int query(){
		if(mini[0]==0) return n2-val[0];
		return n2;
	}
};
segtree seg;
int n,m,cnt;
int begin[100005],end[100005];
vector<int> g[100005];
void dfs(int v,int p){
	begin[v]=cnt++;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		dfs(to,v);
	}
	end[v]=cnt;
}

vector<int> connect[100005];
int ans[100005];
void dfs2(int v,int p){
	REP(i,connect[v].size()){
		int to=connect[v][i];
		seg.add(begin[to],end[to],0,0,seg.n,1);
	}
	ans[v]=seg.query();
	if(ans[v]>0) --ans[v];
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		dfs2(to,v);
	}
	REP(i,connect[v].size()){
		int to=connect[v][i];
		seg.add(begin[to],end[to],0,0,seg.n,-1);
	}
}
int main(){
	cin>>n>>m;
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0,-1);

	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		connect[a].pb(b);
		connect[b].pb(a);
		connect[a].pb(a);
		connect[b].pb(b);
	}

	seg.init(n);
	dfs2(0,-1);

	REP(i,n) printf("%d ",ans[i]);
	putchar('\n');

	return 0;
}