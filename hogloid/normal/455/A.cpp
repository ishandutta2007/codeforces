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

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

const int INF=5e8;

int n;
int cnt[100005];

lint dp[100005][2];
int main(){
	cin>>n;
	REP(i,n){
		int a;scanf("%d",&a);
		cnt[a]++;
	}
	lint res=0;
	memset(dp,-1,sizeof(dp));

	dp[0][0]=0;
	REP(i,100003){
		if(~dp[i][0]){
			chmax(dp[i+1][1],dp[i][0]+cnt[i]*(lint)i);
			chmax(dp[i+1][0],dp[i][0]);
		}
		if(~dp[i][1]){
			chmax(dp[i+1][0],dp[i][1]);
		}
	}
	res=dp[100003][0];
	cout<<res<<endl;




	return 0;
}