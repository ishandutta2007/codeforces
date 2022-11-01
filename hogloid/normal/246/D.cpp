#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
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
int col[100005];
set<int> adj[100005];
int main(){
	cin>>n>>m;
	int maxi=0,who=INF;
	REP(i,n) cin>>col[i],who=min(who,col[i]);

	REP(i,m){
		int a,b;cin>>a>>b;--a;--b;
		if(col[a]!=col[b]){
			adj[col[a]].insert(col[b]);
			adj[col[b]].insert(col[a]);
		}
	}
	REP(i,100005) if((int)adj[i].size()>maxi){
		maxi=adj[i].size();
		who=i;
	}
	printf("%d\n",who);

	return 0;
}