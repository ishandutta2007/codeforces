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

int dp[305][100005];
int n,m,s,e;
int A[100005],B[100005];

vector<int> Bpos[100005];
const int INF=5e8;
int main(){
	cin>>n>>m>>s>>e;

	REP(i,n) scanf("%d",&A[i]);
	REP(i,m){
		scanf("%d",&B[i]);
		Bpos[B[i]].pb(i);
	}


	int MX=s/e+1;

	REP(i,MX) REP(j,n+1) dp[i][j]=INF;
	
	dp[0][0]=0;
	int res=0;
	REP(i,MX) REP(j,n+1) if(dp[i][j]<INF){
		if(i*e+j+dp[i][j]<=s) chmax(res,i);
		
		if(j<n){
			chmin(dp[i][j+1],dp[i][j]);
			int p=lower_bound(ALL(Bpos[A[j]]),dp[i][j])-Bpos[A[j]].begin();
			if(p<Bpos[A[j]].size()) chmin(dp[i+1][j+1],Bpos[A[j]][p]+1);
		}
	}

	cout<<res<<endl;


	return 0;
}