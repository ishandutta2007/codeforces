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
int n,m;
int cost[1005];

pi ar2[1005];
int done[1005];
vector<int> g[2005];
int main(){
	cin>>n>>m;
	REP(i,n){
		cin>>cost[i];
		ar2[i]=mp(cost[i],i);
	}
	REP(i,m){
		int a,b;cin>>a>>b;--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	sort(ar2,ar2+n);
	

	lint res=0;
	for(int i=n-1;i>=0;--i){
		int v=ar2[i].sc;
		REP(j,g[v].size()){
			int to=g[v][j];
			if(!done[to]) res+=cost[to];
		}
		done[v]=1;
	}
	cout<<res<<endl;



	return 0;
}