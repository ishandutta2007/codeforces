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
int n;
pair<pi,int> es[5005];
vector<pi> g[5005];

int size[5005];
int cut[5005];
int prep(int v,int p){
	size[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i].fr;
		if(to==p || cut[to]) continue;
		size[v]+=prep(to,v);
	}
	return size[v];
}
int type;
int cost[2],root[2],all[2];
void dfs(int v,int p){
	int maxi=0;
	REP(i,g[v].size()){
		int to=g[v][i].fr;
		if(to==p || cut[to]) continue;
		maxi=max(maxi,size[to]);
		dfs(to,v);
	}
	if(max(maxi,all[type]-size[v])<cost[type]){
		cost[type]=max(maxi,all[type]-size[v]);
		root[type]=v;
	}
}


lint tot;

int dfs2(int v,int p){
	size[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i].fr;
		if(to==p || cut[to]) continue;
		size[v]+=dfs2(to,v);
		tot+=size[to]*(all[type]-size[to])*(lint)g[v][i].sc;

		tot+=size[to]*(lint)all[type^1]*g[v][i].sc;
	}
	return size[v];
}

int main(){
	scanf("%d",&n);
	REP(i,n-1){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
		
		es[i]=mp(mp(a,b),c);
	}

	lint ans=1e18;

	REP(i,n-1){
		int a=es[i].fr.fr,b=es[i].fr.sc;
		tot=0;
		cost[0]=cost[1]=INF;

		type=0;
		cut[b]=1;
		all[0]=prep(a,b);
		all[1]=n-all[0];
		dfs(a,b);
		dfs2(root[0],-1);
		
		type=1;
		cut[b]=0;
		cut[a]=1;
		all[1]=prep(b,a);
		dfs(b,a);
		dfs2(root[1],-1);

		cut[a]=0;
		tot+=all[0]*all[1]*(lint)es[i].sc;
		ans=min(ans,tot);
	}
	cout<<ans<<endl;

	return 0;
}