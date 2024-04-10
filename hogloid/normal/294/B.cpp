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
vector<int> width[2];
int sum[2][105];
int main(){
	scanf("%d",&n);
	int tot=0;
	REP(i,n){
		int t,w;scanf("%d%d",&t,&w);
		--t;
		width[t].pb(w);
		tot+=w;
	}
	REP(t,2) sort(ALL(width[t]),greater<int>());
	REP(t,2) REP(i,width[t].size()){
		sum[t][i+1]=sum[t][i]+width[t][i];
	}

	
	int res=INF;
	REP(i,width[0].size()+1) REP(j,width[1].size()+1){
		int tick=1*i+2*j;
		int wid=tot-sum[0][i]-sum[1][j];
		
		if(wid<=tick) res=min(res,tick);
	}
	printf("%d\n",res);

	return 0;
}