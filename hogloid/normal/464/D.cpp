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

//const int INF=5e8;

int n,k;

double dp[2][1005];
const int B=1000;
int main(){
	cin>>n>>k;

	int cur=0,nxt=1;
	dp[cur][1]=1;
	
	double res=0;
	REP(i,n){
		REP(j,B) dp[nxt][j]=0;
		REP(j,B) if(dp[cur][j]>1e-100){
			double& p=dp[cur][j];
			dump(i);dump(j);dump(p);
			res+=p*j/2+p*j/(j+1);

			dp[nxt][j+1]+=p/(j+1)/k;
			dp[nxt][j]+=p-(p/(j+1)/k);
		}
		swap(cur,nxt);
	}
	printf("%.10f\n",res);

	






	




	return 0;
}