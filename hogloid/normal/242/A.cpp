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
int x,y,a,b;
vector<pi> ans;
int main(){
	cin>>x>>y>>a>>b;
	REPN(i,x+1,a) REPN(j,y+1,b) if(i>j){
		ans.pb(mp(i,j));
	}
	sort(ALL(ans));
	printf("%d\n",(int)ans.size());
	REP(i,ans.size()) printf("%d %d\n",ans[i].fr,ans[i].sc);

	return 0;
}