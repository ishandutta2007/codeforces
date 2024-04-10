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
vector<pi> g[3005];
pi es[3005];
int dfs(int v,int p){
	int res=0;
	REP(i,g[v].size()){
		pi& e=g[v][i];
		if(e.fr==p) continue;
		res+=e.sc+dfs(e.fr,v);
	}
	return res;
}
int move(int v,int p,int val){
	int res=val;
	REP(i,g[v].size()){
		pi& e=g[v][i];
		if(e.fr==p) continue;
		res=min(res,move(e.fr,v,val+1-e.sc*2));
	}
	return res;
}

int main(){
	cin>>n;
	REP(i,n-1){
		int a,b;cin>>a>>b;--a;--b;
		g[a].pb(mp(b,0));
		g[b].pb(mp(a,1));
		es[i]=mp(a,b);
	}
	int ans=INF;
	if(n<=2) ans=0;
	REP(i,n-1){
		int A,B;
		A=es[i].fr;B=es[i].sc;

		int sum1=dfs(A,B),sum2=dfs(B,A);

		ans=min(ans,move(A,B,sum1)+move(B,A,sum2));
	}
	cout<<ans<<endl;


	return 0;
}