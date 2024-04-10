#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
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
vector<int> g[1005],rg[1005];
pi es[5005];
int mark[1005],cost[1005];
int ans[5005];
bool solve(){
	REP(i,n) cost[i]=INF;
	cost[0]=0;
	REP(hoge,n*2+1) REP(i,m) if(mark[es[i].sc]==3 && mark[es[i].fr]==3){
		cost[es[i].sc]=min(cost[es[i].sc],cost[es[i].fr]+2);
		cost[es[i].fr]=min(cost[es[i].fr],cost[es[i].sc]-1);
	}

	REP(i,m){
		if(mark[es[i].fr]!=3 || mark[es[i].sc]!=3){
			ans[i]=1;
			continue;
		}
		int d=cost[es[i].sc]-cost[es[i].fr];
		if(d!=1 && d!=2) return false;
		ans[i]=d;
	}
	return true;
}

int main(){
	cin>>n>>m;
	REP(i,m){
		int a,b;cin>>a>>b;--a;--b;
		g[a].pb(b);
		rg[b].pb(a);
		es[i]=mp(a,b);
	}
	mark[0]=1;
	REP(i,n) if(mark[i]&1) REP(j,g[i].size()){
		int to=g[i][j];
		mark[to]|=1;
	}
	mark[n-1]|=2;
	for(int i=n-1;i>=0;--i) if(mark[i]&2) REP(j,rg[i].size()){
		int to=rg[i][j];
		mark[to]|=2;
	}

	if(solve()){
		puts("Yes");
		REP(i,m) printf("%d\n",ans[i]);
	}else{
		puts("No");
	}



	return 0;
}