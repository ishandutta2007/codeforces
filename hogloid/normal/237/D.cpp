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
pi es[100005];
vector<int> belong[100005];
int main(){
	cin>>n;
	REP(i,n-1){
		cin>>es[i].fr>>es[i].sc;
		--es[i].fr;
		--es[i].sc;
		belong[es[i].fr].pb(i);
		belong[es[i].sc].pb(i);
	}
	printf("%d\n",n-1);
	REP(i,n-1){
		printf("%d ",2);
		printf("%d %d\n",es[i].fr+1,es[i].sc+1);
	}
	REP(i,n) REP(j,belong[i].size()-1){
		printf("%d %d\n",belong[i][0]+1,belong[i][j+1]+1);
	}
		


	return 0;
}