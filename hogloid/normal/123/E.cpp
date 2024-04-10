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
pi prob[100005];
double ans=0;

int sumx=0,sumy=0;
int size[100005];
double sumprob[100005];
void prep(int v,int p){
	size[v]=1;
	if(p==-1) size[v]=0;
	sumprob[v]=prob[v].fr/(double)sumx;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		prep(to,v);
		sumprob[v]+=sumprob[to];
		size[v]+=size[to];
	}
}
void dfs(int v,int p){
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		dfs(to,v);
		ans+=sumprob[to]*prob[v].sc/sumy*size[to];
	}
	ans+=(1-sumprob[v])*prob[v].sc/sumy*(n-1-size[v]+1);
}

int main(){
	cin>>n;
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	REP(i,n) scanf("%d%d",&prob[i].fr,&prob[i].sc);

	REP(i,n) sumx+=prob[i].fr,sumy+=prob[i].sc;
	
	prep(0,-1);
	
	dfs(0,-1);

	printf("%.10f\n",ans);

	return 0;
}