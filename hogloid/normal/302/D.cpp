#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,d;
int val[105];
pi p[105];

int buf[205][205];
int dp[205][205];
int main(){
	cin>>n>>d;
	REP(i,n-2) cin>>val[i+1];
	REP(i,n){
		cin>>p[i].fr>>p[i].sc;
	}

	if(p[0].fr>p[n-1].fr){
		REP(i,n) p[i].fr*=-1;
	}
	if(p[0].sc>p[n-1].sc) REP(i,n) p[i].sc*=-1;

	REP(i,n) p[i].fr+=100,p[i].sc+=100;

	REPN(i,n-1,1){
		buf[p[i].fr][p[i].sc]=val[i];
	}
	REP(i,205) REP(j,205) dp[i][j]=INF;	

	dp[p[0].fr][p[0].sc]=0;
	priority_queue<pair<int,pi>,vector<pair<int,pi> >,greater<pair<int,pi> > >pq;
	pq.push(mp(0,p[0]));
	
	int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
	while(!pq.empty()){
		pair<int,pi> cur=pq.top();pq.pop();
		if(dp[cur.sc.fr][cur.sc.sc]<cur.fr) continue;
		
		REP(k,4){
			int px=cur.sc.fr+dx[k],py=cur.sc.sc+dy[k];
			if(px<0 || py<0 || px>=201 || py>=201 ||
				dp[px][py]<=cur.fr-buf[px][py]+d) continue;
			dp[px][py]=cur.fr-buf[px][py]+d;
			pq.push(mp(dp[px][py],mp(px,py)));
		}
	}

	int worth=dp[p[n-1].fr][p[n-1].sc];

	printf("%d\n",worth);

	return 0;
}