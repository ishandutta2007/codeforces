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
const lint INF=1e18;

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint a){
#ifdef ONLINE_JUDGE
	printf("%I64d",a);
#else
	printf("%lld",a);
#endif
}


int t[5][5];

lint dp[45][3][3];
int main(){
	REP(i,3) REP(j,3) cin>>t[i][j];
	int n;cin>>n;

	REP(i,3) REP(j,3) dp[1][i][j]=t[i][j];
	
	REP(i,3) REP(j,3) REP(k,3) chmin(dp[1][i][k],dp[1][i][j]+dp[1][j][k]);
	for(int i=2;i<=n;++i) REP(j,3) REP(k,3) if(j!=k){
		int l;
		for(l=0;l<3;++l){
			if(l!=j && l!=k) break;
		}
		dp[i][j][k]=min(dp[i-1][j][l]+t[j][k]+dp[i-1][l][k],
						dp[i-1][j][k]+t[j][l]+dp[i-1][k][j]+t[l][k]+dp[i-1][j][k]);
	}

	lint res=dp[n][0][2];
	cout<<res<<endl;

	return 0;
}