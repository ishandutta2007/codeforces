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

int leftlen[50][50];
int h,w,q;
char buf[50][50];
int dp[50][50][50][50];
int main(){
	cin>>h>>w>>q;
	REP(i,h) scanf("%s",buf[i]);

	REP(i,h) REP(j,w){
		int back=(j==0?0:leftlen[i][j-1]);
		leftlen[i][j]=(buf[i][j]=='0'?1+back:0);
	}

	REP(i,h) REP(j,w){

		REPN(k,h,i) REPN(l,w,j){
			
			int tmp=dp[i][j][k][l+1]+dp[i][j][k+1][l]-dp[i][j][k][l];
			int wid=l-j+1;
			for(int k2=k;k2>=i;--k2){
				chmin(wid,leftlen[k2][l]);
				tmp+=wid;
			}
			dp[i][j][k+1][l+1]=tmp;
		}
	}
	REP(hoge,q){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);--a;--b;
		printf("%d\n",dp[a][b][c][d]);
	}






	return 0;
}