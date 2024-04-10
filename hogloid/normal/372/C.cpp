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

const lint INF=1e18;

int n,m,d;

lint dp[2][150005];

int indx[150005];
int cur=0,nxt=1;

void renew(lint len){
	int st=0,en=0;
	REP(i,n){
		while(en-st && dp[cur][indx[en-1]]<=dp[cur][i]) --en;
		indx[en++]=i;

		chmax(dp[nxt][i],dp[cur][indx[st]]);
		if(indx[st]==i-len) ++st;
	}
}

int main(){

	cin>>n>>m>>d;
	int last=1;
	REP(hoge,m){
		int a,b,t;scanf("%d%d%d",&a,&b,&t);--a;
		int dif=t-last;
		lint len=dif*(lint)d;

		REP(i,n) dp[nxt][i]=-INF;

		renew(len);

		reverse(dp[0],dp[0]+n);
		reverse(dp[1],dp[1]+n);

		renew(len);

		reverse(dp[0],dp[0]+n);
		reverse(dp[1],dp[1]+n);

		REP(i,n) dp[nxt][i]+=b-abs(a-i);

		swap(cur,nxt);
		last=t;
	}
	lint res=-INF;
	REP(i,n) chmax(res,dp[cur][i]);

	cout<<res<<endl;






	return 0;
}