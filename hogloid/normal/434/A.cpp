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

int ar[100005];
vector<int> adj[100005];
int main(){
	cin>>n>>m;
	REP(i,m) scanf("%d",&ar[i]),--ar[i];

	lint base=0;
	REP(i,m-1){
		int a=ar[i],b=ar[i+1];
		if(a!=b){
			adj[a].pb(b);
			adj[b].pb(a);
		}
		base+=abs(a-b);
	}
	REP(i,n) sort(ALL(adj[i]));
	
	lint res=base;
	REP(i,n) if(!adj[i].empty()){
		lint ever=0,aft=0;

		REP(j,adj[i].size()) ever+=abs(adj[i][j]-i);

		int medi=adj[i][adj[i].size()/2];

		REP(j,adj[i].size()) aft+=abs(adj[i][j]-medi);

		chmin(res,base+aft-ever);
	}
	cout<<res<<endl;


	


	return 0;
}