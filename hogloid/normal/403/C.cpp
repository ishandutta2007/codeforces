#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int n;
int m=0;
int mat[2005][2005];
int vis[2005],order[2005];
void dfs(int v){
	vis[v]=1;
	REP(i,n) if(mat[v][i] && !vis[i]) dfs(i);
	order[m++]=v;
}
void rdfs(int v){
	vis[v]=1;
	REP(i,n) if(mat[i][v] && !vis[i]) rdfs(i);
}

int main(){
	cin>>n;
	REP(i,n) REP(j,n){
		int a;scanf("%d",&a);
		if(a>0) mat[i][j]=1;
		else mat[i][j]=0;
	}

	REP(i,n) if(!vis[i]) dfs(i);

	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(int i=n-1;i>=0;--i) if(!vis[order[i]]){
		rdfs(order[i]);
		++cnt;
	}
	

	int fail=(cnt!=1);
	if(fail) puts("NO");
	else puts("YES");



	return 0;
}