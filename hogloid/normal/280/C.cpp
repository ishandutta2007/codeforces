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
double res;

void dfs(int v,int p,int d){
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		dfs(to,v,d+1);
	}
	res+=1.0/d;
}

int main(){
	cin>>n;
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}

	res=0;
	dfs(0,-1,1);


	printf("%.10f\n",res);



	return 0;
}