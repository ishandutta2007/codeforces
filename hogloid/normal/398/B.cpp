#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}
//const int INF=5e8;

double dp[2005][2005];
int n,m;
int mark[2005][2005];
int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		mark[a][b]=1;
	}


	int R=0,C=0;

	REP(i,n){
		int flag=0;
		REP(j,n) flag|=mark[i][j];
		if(flag) ++C;

		flag=0;
		REP(j,n) flag|=mark[j][i];
		if(flag) ++R;
	}
	
	dp[n][n]=0;
	for(int i=n;i>=R;--i) for(int j=n;j>=C;--j){
		if(i==n && j==n) continue;
		double expTime=1.0*n*n/(n*n-i*j);
		double all=n*n-j*i;
		dump(expTime);
		double p=(n-i)*(n-j)/all;
		dp[i][j]=0;
		dump(p);
		dp[i][j]+=dp[i+1][j+1]*p;
		dump(dp[i][j]);
		
		p=i*(n-j)/all;
		dump(p);
		dp[i][j]+=dp[i][j+1]*p;
		dump(dp[i][j]);

		p=(n-i)*j/all;
		dump(p);
		dp[i][j]+=dp[i+1][j]*p+expTime;

		dump(i);dump(j);dump(dp[i][j]);
	}
	double res=dp[R][C];

	printf("%.15f\n",res);



	return 0;
}