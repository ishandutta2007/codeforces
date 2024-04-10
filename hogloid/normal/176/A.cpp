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
int n,m,k;
int cost[15][105],prof[15][105],am[15][105];

int tar[10005];
int main(){
	cin>>n>>m>>k;
	REP(i,n){
		scanf("%*s");
		REP(j,m) cin>>cost[i][j]>>prof[i][j]>>am[i][j];
	}
	
	int res=0;
	REP(i,n) REP(i2,n) if(i!=i2){
		int tmp=0;
		int cnt=0;
		REP(j,m) if(cost[i][j]<prof[i2][j]){
			int trans=min(am[i][j],k);
			REP(hoge,trans) tar[cnt++]=prof[i2][j]-cost[i][j];
		}
		sort(tar,tar+cnt,greater<int>());
		REP(j,min(k,cnt)) tmp+=tar[j];
		res=max(res,tmp);
	}

	cout<<res<<endl;


	return 0;
}