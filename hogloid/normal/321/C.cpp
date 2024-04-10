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
vector<int> g[100005];
int cut[100005];
int res[100005];
int size[100005];
int getsize(int v,int p){
	size[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p || cut[to]) continue;
		size[v]+=getsize(to,v);
	}
	return size[v];
}
int rcost,root,all;
void getroot(int v,int p){
	int mxch=all-size[v];
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p || cut[to]) continue;
		getroot(to,v);
		mxch=max(mxch,size[to]);
	}
	if(mxch<rcost){
		rcost=mxch;
		root=v;
	}
}

void dfs(int v,int dep){
	
	all=getsize(v,-1);

	rcost=INF;
	getroot(v,-1);
	
	v=root;
	res[v]=dep;
	if(all==1) return;
	
	cut[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(cut[to]) continue;
		dfs(to,dep+1);
	}
}

int main(){
	scanf("%d",&n);
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}

	dfs(0,0);
	REP(i,n) printf("%c%c",res[i]+'A',i==n-1?'\n':' ');

	return 0;
}