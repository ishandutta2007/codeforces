#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<list>
#include<cstdio>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#define REP(num,num2) for(int num=0;num<(int)num2;++num)
#define REPN(num,num2,init) for(int num=init;num<(int)num2;++num)
#define ITR(x) __typeof((x).begin())
#define FOR(itr,data) for(ITR(data) itr=(data).begin();itr!=(data).end();++itr)
#define ALL(typ) (typ).begin(),(typ).end()
#define SPR(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz size()
#define INF ((int)1e9)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef long long int lint;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vp;
typedef pair<int,int> pi;
const double PI  = acos(-1.0);
template<class T> void debug(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
int n,l,K;
pair<int,double> got[205];
double win[205];
int prize[205];
double dp[205][205][205];//dp[round][won][rest]
int main(){
	scanf("%d%d%d",&n,&l,&K);
	REP(i,n) scanf("%lf",&win[i]),win[i]/=100.0;
	int cnt=0,cnt2=0;
	REP(i,n){
		scanf("%d",&prize[i]);
		got[i]=mp(prize[i],win[i]);
	}
	sort(got,got+n,greater<pair<int,double> >());

	dp[0][0][K]=1.0;
	REP(i,n) REP(j,i+1) REP(k,205) if(dp[i][j][k]>0){
		if(k+got[i].fr>=0) dp[i+1][j+1][min(204,k+got[i].fr)]+=dp[i][j][k]*got[i].sc;
		dp[i+1][j][k]+=dp[i][j][k]*(1-got[i].sc);
	}
	double res=0;
	REPN(i,n+1,l) REP(j,205) res+=dp[n][i][j];

	printf("%.8f\n",res);
	return 0;
}