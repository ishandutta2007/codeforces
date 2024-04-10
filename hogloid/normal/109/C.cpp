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
vector<pi> g[100005];

int vis[100005];

int dfs(int v){
	vis[v]=1;
	int res=1;
	REP(i,g[v].size()){
		int to=g[v][i].fr;
		if(vis[to] || g[v][i].sc) continue;
		res+=dfs(to);
	}
	return res;
}
bool isluck(int a){
	while(a>0){
		if(a%10!=4 && a%10!=7) return false;
		a/=10;
	}
	return true;
}

int main(){
	cin>>n;
	REP(i,n-1){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;

		if(isluck(c)) c=1;
		else c=0;
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
	}

	lint res=0;	
	vector<int> group;
	REP(i,n) if(!vis[i]){
		int cnt=dfs(i);
		res+=cnt*(lint)(n-cnt)*(n-cnt-1);
	}

	cout<<res<<endl;




	return 0;
}