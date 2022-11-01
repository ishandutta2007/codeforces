#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,lint> pi;//(id,C)
int n,m,p;
int d[100005];
lint tim[100005];

lint dp[105][100005];
static const lint INF =1e18;
lint sum[100005];
pi stk[100005];
int n2;

inline lint getsum(int l,int r){
	if(l>=r) return 0;
	return (tim[r-1]-tim[l])*(r-l)-(sum[r]-sum[l]-tim[l]*(r-l));
}

inline double getdiv(pi a,pi b){
	lint dif=b.sc-a.sc-getsum(a.fr,b.fr+1);
	return dif/(double)(b.fr-a.fr);
}

	
int main(){
	cin>>n>>m>>p;
	REP(i,n-1) scanf("%d",&d[i+1]);
	
	REP(i,n-1) d[i+1]+=d[i];

	REP(i,m){
		int h,t;scanf("%d%d",&h,&t);--h;
		t-=d[h];
		tim[i]=t;
	}
	sort(tim,tim+m);

	REP(i,m) sum[i+1]=sum[i]+tim[i];
	
//	debug(tim,tim+m);
	REP(i,105) REP(j,100005) dp[i][j]=INF;
	dp[0][0]=0;
	prl;
	REP(i,p){
		n2=0;
		int st=0,en=0;
		REP(j,m+1) {
		//	dp[i+1][j+1]=min(dp[i][j],dp[i+1][j+1]);
			while(st+1<en && getsum(stk[st+1].fr,j)+stk[st+1].sc<=
				stk[st].sc+getsum(stk[st].fr,j)) ++st;
			
			dp[i+1][j]=min(dp[i][j],stk[st].sc+getsum(stk[st].fr,j));

			pi ins=mp(j,dp[i][j]);
			while(st+1<en){
				double bord=getdiv(stk[en-2],stk[en-1])+tim[stk[en-1].fr];
				double bord3=getdiv(stk[en-1],ins)+tim[j];
				if(bord3<=bord) --en;
				else break;
			}
			stk[en++]=ins;
		}
	}

	lint res=dp[p][m];

	cout<<res<<endl;
	

	return 0;
}