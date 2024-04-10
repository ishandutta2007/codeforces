#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
struct BIT{
	int val[400005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=0;
	}
	void add(int k,int a){
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	int query(int k){
		int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
};
BIT bit;
int n,k;
int begin[100005],end[100005];
vector<int> g[100005];
int par[20][100005];
int depth[100005];
void dfs(int v,int p,int& cnt,int dep){
	begin[v]=cnt++;
	depth[v]=dep;
	par[0][v]=p;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		dfs(to,v,cnt,dep+1);
	}
	end[v]=cnt++;
}
int lca(int a,int b){
	if(depth[a]>depth[b]) swap(a,b);
	int dif=depth[b]-depth[a];
	REP(i,20) if(dif>>i&1){
		b=par[i][b];
	}
	if(a==b) return a;
	for(int i=19;i>=0;--i) if(par[i][a]!=par[i][b]){
		a=par[i][a];
		b=par[i][b];
	}
	return par[0][a];
}
pi es[100005];
int main(){
	scanf("%d",&n);
	bit.init(n*2);
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);g[b].pb(a);
		es[i]=mp(a,b);
	}
	int cnt=0;
	dfs(0,-1,cnt,0);
	REP(i,19) REP(j,n){
		if(par[i][j]==-1) par[i+1][j]=-1;
		else par[i+1][j]=par[i][par[i][j]];
	}

	scanf("%d",&k);
	REP(i,k){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		bit.add(begin[a],1);
		bit.add(begin[b],1);
		
		int l = lca(a,b);
		bit.add(begin[l],-2);
	}
	REP(i,n-1){
		if(depth[es[i].fr]>depth[es[i].sc]) swap(es[i].fr,es[i].sc);
		int b=es[i].sc;
		printf("%d%c",bit.query(end[b])-bit.query(begin[b]),i==n-2?'\n':' ');
	}


	return 0;
}