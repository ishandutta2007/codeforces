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
lint num[100005];
vector<int> g[100005];

lint ans;
lint pl[100005],mi[100005];
void dfs(int v,int p){
	lint P=0,M=0;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		dfs(to,v);
		P=max(P,pl[to]);
		M=max(M,mi[to]);
	}
	lint dif=num[v]-(P-M);
	if(dif>0) P+=dif;
	else M-=dif;

	pl[v]=P;
	mi[v]=M;
}


int main(){
	cin>>n;
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	REP(i,n) cin>>num[i];

	dfs(0,-1);
	
	cout<<pl[0]+mi[0]<<endl;

	return 0;
}