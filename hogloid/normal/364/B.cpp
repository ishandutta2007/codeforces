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

int n,d;
int pr[55];
int day[55];

int mark[10005*55];

int dp[10005*55];
int main(){
	cin>>n>>d;
	REP(i,n) cin>>pr[i];
	sort(pr,pr+n);
	
	mark[0]=1;
	REP(i,n){
		for(int j=10000*n;j>=0;--j) if(mark[j]){
			mark[j+pr[i]]=1;
		}
	}
	
	vector<int> ps;
	REP(i,10000*n+1) if(mark[i]) ps.pb(i);
		
	int j=0;

	int price=0,takeDays=0;
	REP(i,ps.size()){
		if(i==0) dp[i]=0;
		else{
			while(ps[i]-ps[j]>d) ++j;
			if(j<i) dp[i]=dp[j]+1;
			else dp[i]=INF;
		}
		if(dp[i]<INF){
			price=ps[i];
			takeDays=dp[i];
		}
	}

	printf("%d %d\n",price,takeDays);	
	return 0;
}