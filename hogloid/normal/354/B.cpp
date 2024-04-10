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
char buf[25][25];

int dp[45][1<<20];
int score[300];
int main(){
	cin>>n;
	REP(i,n) scanf("%s",buf[i]);

	
	score[0]=1;
	score[1]=-1;

	dp[n*2-2][1]=0;
	for(int i=n*2-3;i>=0;--i){
		int wid=min(i+1,2*n-1-i);

		REPN(j,(1<<wid),1){
			int nbit[26]={0};
			REP(k,wid) if(j>>k&1){
				int y=k+max(0,i-(n-1)),x=i-y;
				dump(mp(y,x));
				
				if(y+1<n){
					nbit[buf[y+1][x]-'a']|=(1<<(y+1-max(0,i+1-(n-1))));
				}
				if(x+1<n){
					nbit[buf[y][x+1]-'a']|=(1<<(y-max(0,i+1-(n-1))));
				}
			}
			if(i&1) dp[i][j]=-INF;
			else dp[i][j]=INF;

			REP(k,26) if(nbit[k]>0){
				if(i&1){//maximize
					chmax(dp[i][j],dp[i+1][nbit[k]]+score[k]);
				}else{
					chmin(dp[i][j],dp[i+1][nbit[k]]+score[k]);
				}
			}
		}
	}

	int res=dp[0][1]+score[buf[0][0]-'a'];
	dump(res);

	puts(res>0?"FIRST":res<0?"SECOND":"DRAW");

	return 0;
}