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

int h,w;
char buf[1005][1005];

int cost[1005][1005];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int main(){
	cin>>h>>w;
	REP(i,h) scanf("%s",buf[i]);
	
	int sx,sy,gx,gy;
	REP(i,h) REP(j,w){
		if(buf[i][j]=='E'){
			gx=j;gy=i;
		}else if(buf[i][j]=='S'){
			sx=j;sy=i;
		}
	}

	memset(cost,-1,sizeof(cost));
	cost[gy][gx]=0;
	queue<pi> q;q.push(mp(gy,gx));
	while(!q.empty()){
		int cy=q.front().fr,cx=q.front().sc;q.pop();
		REP(d,4){
			int px=cx+dx[d],py=cy+dy[d];
			if(px<0 || py<0 || px>=w || py>=h || ~cost[py][px] || buf[py][px]=='T') continue;
			cost[py][px]=cost[cy][cx]+1;
			q.push(mp(py,px));
		}
	}

	int C=cost[sy][sx];
	
	int res=0;
	REP(i,h) REP(j,w) if(buf[i][j]>='0' && buf[i][j]<='9' && ~cost[i][j]){
		if(cost[i][j]<=C) res+=buf[i][j]-'0';
	}
	cout<<res<<endl;




	return 0;
}