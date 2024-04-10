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

const int INF=1e7;

int h,w;
char buf[25][25];
int c;
int val[10];

int cost[25][25][1<<10];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
typedef pair<pi,int> statt;

int cross[25][25][4];
int main(){
	cin>>h>>w;
	REP(i,h) scanf("%s",buf[i]);
	
	int sy,sx;
	REP(i,h) REP(j,w){
		if(buf[i][j]>='1' && buf[i][j]<='9'){
			buf[i][j]--;
			++c;
		}else if(buf[i][j]=='S'){
			sy=i;sx=j;
		}
	}
	REP(i,c) cin>>val[i];
	REP(i,h) REP(j,w) if(buf[i][j]=='B'){
		val[c]=-INF;
		buf[i][j]='0'+c;
		++c;
	}

	REP(i,h) REP(j,w){
		if(i+1<h){
			int sum=0;
			REP(k,j) if(buf[i+1][k]>='0' && buf[i+1][k]<='9'){
				sum|=(1<<(buf[i+1][k]-'0'));
			}
			cross[i][j][0]=sum;
		}
		if(i>0){
			int sum=0;
			REP(k,j) if(buf[i][k]>='0' && buf[i][k]<='9'){
				sum|=(1<<(buf[i][k]-'0'));
			}
			cross[i][j][2]=sum;
		}
	}



	memset(cost,-1,sizeof(cost));
	cost[sy][sx][0]=0;
	queue<statt>q;q.push(mp(mp(sy,sx),0));
	while(!q.empty()){
		statt cur=q.front();q.pop();

		int x=cur.fr.sc,y=cur.fr.fr,bit=cur.sc;
		REP(d,4){
			int px=x+dx[d],py=y+dy[d];
			if(px>=w || py>=h || px<0 || py<0 || buf[py][px]=='#' ||
					(buf[py][px]>='0' && buf[py][px]<='9')) continue;

			int nbit=(bit^cross[y][x][d]);
			if(cost[py][px][nbit]==-1){
				cost[py][px][nbit]=cost[y][x][bit]+1;
				q.push(mp(mp(py,px),nbit));
			}
		}
	}
	
	int res=0;
	REP(i,1<<c) if(cost[sy][sx][i]!=-1){
		int sum=0;
		REP(j,c) if(i>>j&1) sum+=val[j];
		chmax(res,-cost[sy][sx][i]+sum);
	}
	cout<<res<<endl;








	return 0;
}