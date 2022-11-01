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
int par[100005],depth[100005],root[100005],begin[100005],end[100005];
vector<int> g[100005];
int par2[20][100005];
int n;
void rec(int v){
	if(depth[v]!=-1) return;
	if(par[v]==-1){
		depth[v]=0;
		root[v]=v;
		return;
	}else{
		rec(par[v]);
		depth[v]=depth[par[v]]+1;
		root[v]=root[par[v]];
	}
}
int cnt;
vector<int> seq[100005];
void dfs(int v){
	seq[depth[v]].pb(cnt);
	begin[v]=cnt++;
	REP(i,g[v].size()){
		int to=g[v][i];
		dfs(to);
	}
	end[v]=cnt;
}
int get(int a,int dep){
	return lower_bound(ALL(seq[dep]),a)-seq[dep].begin();
}
int tosize[100005];
int main(){
	scanf("%d",&n);
	REP(i,n){
		int a;scanf("%d",&a);
		--a;
		par[i]=a;
		if(a>=0) g[par[i]].pb(i);
	}
	memset(depth,-1,sizeof(depth));
	REP(i,n) if(depth[i]==-1){
		rec(i);
	}
	REP(i,n) par2[0][i]=par[i];
	REP(i,19) REP(j,n){
		if(par2[i][j]==-1) par2[i+1][j]=-1;
		else par2[i+1][j]=par2[i][par2[i][j]];
	}
	REP(i,n) if(root[i]==i){
		dfs(i);
	}
	int m;scanf("%d",&m);
	REP(hoge,m){
		int v,p;scanf("%d%d",&v,&p);
		--v;
		int pp=v;
		REP(i,20) if(pp>=0 && p>>i&1) pp=par2[i][pp];
		if(pp==-1){
			printf("0 ");
			continue;
		}
		printf("%d ",get(end[pp],depth[v])-get(begin[pp],depth[v])-1);
	}
	putchar('\n');
	
	return 0;
}