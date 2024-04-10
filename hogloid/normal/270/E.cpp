#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
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
int n,m;
vector<pair<pi,pi> > g[200005];
int in[200005],flow[200005];
int vis[200005];
int ans[200005];

int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
		g[a].pb(mp(mp(b,c),mp(0,i)));
		g[b].pb(mp(mp(a,c),mp(1,i)));
		flow[a]+=c;
		flow[b]+=c;
	}
	
	memset(ans,-1,sizeof(ans));
	
	queue<int> q;q.push(0);
	while(!q.empty()){
		int v=q.front();q.pop();
		vis[v]=1;
		REP(i,g[v].size()){
			pair<pi,pi>& e=g[v][i];
			if(vis[e.fr.fr]) continue;
			in[e.fr.fr]+=e.fr.sc;
			ans[e.sc.sc]=e.sc.fr;
			if(in[e.fr.fr]==flow[e.fr.fr]/2 && e.fr.fr!=n-1) q.push(e.fr.fr);
		}
	}


	REP(i,m) printf("%d\n",ans[i]);





	return 0;
}