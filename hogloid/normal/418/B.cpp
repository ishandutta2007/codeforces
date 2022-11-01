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

int n,m;
lint b;
pair<pi,int> fri[105];//((monitor,cost),bit)

lint dp[1<<20];
const lint INF2=2e18;
int main(){
	cin>>n>>m>>b;
	REP(i,n){
		cin>>fri[i].fr.sc>>fri[i].fr.fr;
		int mi;cin>>mi;

		int bit=0;
		REP(j,mi){
			int a;cin>>a;
			--a;
			bit|=(1<<a);
		}
		fri[i].sc=bit;
	}
	
	sort(fri,fri+n);
	

	REP(i,1<<20) dp[i]=INF2;
	dp[0]=0;
	lint res=INF2;
	REP(i,n){
		for(int j=(1<<m)-1;j>=0;--j) if(dp[j]<INF2){
			chmin(dp[j|fri[i].sc],dp[j]+fri[i].fr.sc);
		}

		chmin(res,dp[(1<<m)-1]+fri[i].fr.fr*b);
	}
	if(res==INF2) res=-1;
	cout<<res<<endl;


	return 0;
}