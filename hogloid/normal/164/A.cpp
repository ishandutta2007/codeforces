#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<list>
#include<cstdio>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#define REP(num,num2) for(int num=0;num<(int)num2;++num)
#define REPN(num,num2,init) for(int num=init;num<(int)num2;++num)
#define ITR(x) __typeof((x).begin())
#define FOR(itr,data) for(ITR(data) itr=(data).begin();itr!=(data).end();++itr)
#define ALL(typ) (typ).begin(),(typ).end()
#define SPR(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz size()
#define INF ((int)1e9)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef long long int lint;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vp;
typedef pair<int,int> pi;
const double PI  = acos(-1.0);
template<class T> void debug(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
int n,m;
vi g[100005],rg[100005];
int st[100005];
int reachto[100005],reachfrom[100005];
void dfs(int v){
	reachto[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(reachto[to]==0) dfs(to);
	}
}
void rdfs(int v){
	reachfrom[v]=1;
	if(st[v]!=1){
		REP(i,rg[v].size()){
			int to=rg[v][i];
			if(reachfrom[to]==0) rdfs(to);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&st[i]);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		rg[b].pb(a);
	}
	REP(i,n) if(st[i]==1 && reachto[i]==0){
		dfs(i);
	}
	REP(i,n) if(st[i]==2 && reachfrom[i]==0){
		rdfs(i);
	}
	
	REP(i,n){
		if(reachto[i] && reachfrom[i]) printf("%d\n",1);
		else printf("%d\n",0);
	}
	return 0;
}