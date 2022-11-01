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
int n,p;
int size[55];

double dp[105][105][105];
double fact[55];
int main(){
	cin>>n;
	REP(i,n) cin>>size[i];
	cin>>p;

	fact[0]=1;
	REP(i,54) fact[i+1]=fact[i]*(i+1);
	
	double res=0;
	REP(i,n){
		rotate(size,size+1,size+n);
		REP(j,55) REP(k,55) REP(l,55) dp[j][k][l]=0;

		dp[1][0][0]=1.0;
		for(int j=1;j<n;++j) for(int k=0;k<=p;++k) REP(l,n) if(dp[j][k][l]>0.5){
			dp[j+1][k+size[j]][l+1]+=dp[j][k][l];
			dp[j+1][k][l]+=dp[j][k][l];
		}
		
		double sum=0;
		for(int j=max(0,p-size[0]+1);j<=p;++j) REP(l,n){
			sum+=dp[n][j][l]*fact[n-l-1]*(n-l)*fact[l];
		}
		res+=sum;
	}
	res/=fact[n];
	
	res=n-res;
	printf("%.10f\n",res);

	return 0;
}