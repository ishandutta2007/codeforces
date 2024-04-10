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

char s[2005],p[505];
int n,m;

int nxtpos[2005];

int dp[2005][2005];
int main(){
	scanf("%s%s",s,p);
	n=strlen(s);
	m=strlen(p);

	REP(i,n){
		int k=0;
		nxtpos[i]=INF;
		REPN(j,n,i){
			if(s[j]==p[k]) ++k;
			if(k==m) {
				nxtpos[i]=j+1;
				break;
			}
		}
	}

	memset(dp,-1,sizeof(dp));

	dp[0][0]=0;
	REP(i,n) REP(j,n+1) if(dp[i][j]>=0){
		int nxt=nxtpos[i];
		int ers=nxt-i-m;
		
		if(nxt<INF){
			chmax(dp[nxt][j+ers],dp[i][j]+1);
		}
		chmax(dp[i+1][j],dp[i][j]);
		chmax(dp[i+1][j+1],dp[i][j]);
	}
	REP(i,n+1){
		printf("%d%c",dp[n][i],i==n?'\n':' ');
	}

	return 0;
}