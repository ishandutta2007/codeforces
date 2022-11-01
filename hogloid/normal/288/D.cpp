#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

#include<map>
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
typedef unsigned long long int lint;
typedef pair<int,int> pi;
int n;
lint res,res2;

lint curcomb,cursum;
vector<int> g[80005],ch[80005];
pi es[80005];
int deg[80005];

int size[80005];
int par[80005];
int getsize(int v,int p){
	par[v]=p;
	size[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		size[v]+=getsize(to,v);
		ch[v].pb(to);
	}
	return size[v];
}

lint dfs(int v){
	lint res=0;
	lint sum=size[v]*(lint)(size[v]);
	REP(i,ch[v].size()){
		int to=ch[v][i];
		sum-=size[to]*(lint)size[to];
		res+=dfs(to);
	}
	--sum;
	sum/=2;//combination
	
	return sum*sum+2*sum*size[v]*(n-size[v])+res;
}

int main(){
	cin>>n;
	REP(i,n-1){
		int a,b;cin>>a>>b;--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}

	getsize(0,-1);

	lint sub=dfs(0);
	res=n*(lint)(n-1)/2;
	res=res*res;
	res=res-sub;
	
	cout<<res<<endl;

	return 0;
}