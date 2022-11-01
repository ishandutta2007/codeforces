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

int col[]=
{0,1,2,1,2,0,1,2,0,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1,2,0,2,1};
lint len[]=
{2,1,1,2,2,4,2,4,8,12,1,17,1,23,4,35,1,53,5,76,5,103,19,155,7,236,25,341,23,463,86,697,32,1060,115,1532,106,2081,389,3136,145,4769,518,6892,479,9364,1751,14110,655,21458,2333,31012,2158,42137,7880,63493,2950,96560,10499,139552,9713,189616,35461,285716,13277,434518,47248,627983,43709,853270,159577,1285721,59747,1955329,212618,2825923,196691,3839713,718099,5785742,268864,8798978,956783,12716653,885110,17278708,3231446,26035837,1209890,39595399,4305526,57224936,3982997,77754184,14541509,117161266,5444506,178179293,19374869,257512210,17923489,115568300};

int LEN=102;

int n,p;
const lint mod=1000000007;
lint dp[1005][4];
int sum[105];

lint pat[3];
inline void add(lint& a,lint b){
	b%=mod;
	a+=b;
	a%=mod;
}

int main(){
	cin>>n>>p;
	int ever=1;
	REP(i,LEN){
		sum[i]=ever;
		if(ever+len[i]>=p) len[i]=p-ever;
		
		ever+=len[i];
		if(ever==p){
			LEN=i+1;break;
		}
	}
	sum[LEN]=ever;

	REP(i,LEN){
		lint a=p-sum[i+1]+1,b=p-sum[i];
		add(pat[col[i]],(a+b)*len[i]/2);

	}

	
	dp[0][0]=1;
	REP(i,n) REP(j,4) if(dp[i][j]) REP(k,3){
		add(dp[i+1][j^k],dp[i][j]*pat[k]);
	}

	lint res=0;
	REPN(k,4,1) add(res,dp[n][k]);
	cout<<res<<endl;
	
	return 0;
}