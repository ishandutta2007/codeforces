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

int n,m,k;
int tot[15];
int res[20005];
int belong[20005][15];
int main(){
	cin>>n>>m>>k;
	REP(i,n) REP(j,m){
		int t;cin>>t;
		belong[i][j]=t;
	}
	REP(i,k){
		int x,y;cin>>x>>y;
		--x;--y;
		++tot[y];
		--res[x];
	}
	REP(i,n) REP(j,m) res[i]+=tot[j]*belong[i][j];

	REP(i,n) cout<<res[i]<<(i==n-1?'\n':' ');

	return 0;
}