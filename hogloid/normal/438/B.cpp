#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int n,m;
int val[100005];
pi verts[100005];
vector<int> g[100005];
int valid[100005];


double ans;
struct uf{
	int par[100005];
	int size[100005];
	uf(){
		memset(par,-1,sizeof(par));
		REP(i,100005) size[i]=1;
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b,int wei){
		a=root(a);b=root(b);

		if(a==b) return;
		ans+=size[a]*(double)size[b]*wei;
		par[a]=b;
		size[b]+=size[a];
	}
};
uf u;
int main(){
	ans=0;
	cin>>n>>m;
	REP(i,n){
		cin>>val[i];
		verts[i]=mp(val[i],i);
	}
	REP(i,m){
		int a,b;cin>>a>>b;--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	sort(verts,verts+n);

	for(int i=n-1;i>=0;--i){
		int v=verts[i].sc;
		
		valid[v]=1;
		REP(j,g[v].size()){
			int to=g[v][j];
			if(valid[to]) u.unite(v,to,verts[i].fr);
		}
	}
	ans/=n;
	ans/=(n-1);
	ans*=2;

	printf("%.10f\n",ans);
	return 0;
}