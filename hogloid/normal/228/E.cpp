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
int n,m;
int g[105][105];
int col[105];
int fail;
void dfs(int v){
	REP(i,n) if(g[v][i]!=-1){
		int exp=(col[v]^g[v][i]^1);
		if(col[i]==exp) continue;
		if(col[i]==-1){
			col[i]=exp;
			dfs(i);
		}else{
			fail=1;
		}
		if(fail) return;
	}
}

int main(){
	cin>>n>>m;
	memset(g,-1,sizeof(g));
	REP(i,m){
		int a,b,c;cin>>a>>b>>c;
		--a;--b;
		g[a][b]=g[b][a]=c;
	}
	memset(col,-1,sizeof(col));
	REP(i,n) if(col[i]==-1){
		col[i]=0;
		dfs(i);
		if(fail) break;
	}
	if(fail) puts("Impossible");
	else{
		vector<int> res;
		REP(i,n) if(col[i]) res.pb(i);
		printf("%d\n",(int)res.size());
		REP(i,res.size()) printf("%d\n",res[i]+1);
	}


	return 0;
}