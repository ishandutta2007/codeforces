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

int h,w;
int buf[1005][1005];
queue<pi> q;
int mx[4][1005][1005];
int vis[1005][1005];
void doit(int mx[1005][1005],int sy,int sx,int* dx,int* dy){
	q.push(mp(sy,sx));
	CLR(vis);

	REP(i,h) REP(j,w) mx[i][j]=-1;
	mx[sy][sx]=buf[sy][sx];
	
	while(!q.empty()){
		pi cur=q.front();q.pop();
		REP(i,2){
			int px=cur.sc+dx[i],py=cur.fr+dy[i];
			if(py<0 || px<0 || px>=w || py>=h) continue;
			chmax(mx[py][px],mx[cur.fr][cur.sc]+buf[py][px]);
			if(!vis[py][px]){
				vis[py][px]=1;
				dump(py);dump(px);
				q.push(mp(py,px));
			}
		}
	}
}
int main(){
	cin>>h>>w;
	REP(i,h) REP(j,w) scanf("%d",&buf[i][j]);
	
	pi st[4]={mp(0,0),mp(h-1,0),mp(0,w-1),mp(h-1,w-1)};
	int dx[4][2]={{1,0},{1,0} ,{-1,0},{-1,0}};
	int dy[4][2]={{0,1},{0,-1},{0,1}, {0,-1}};

	REP(i,4){
		doit(mx[i],st[i].fr,st[i].sc,dx[i],dy[i]);
	}

	REP(i,4){
		dump(i);
		REP(j,h) debug(mx[i][j],mx[i][j]+w);
	}
	
	int res=-1;
	REPN(i,h-1,1) REPN(j,w-1,1){
		int tmp=mx[0][i-1][j]+mx[3][i+1][j]+mx[1][i][j-1]+mx[2][i][j+1];
		int tmp2=mx[0][i][j-1]+mx[3][i][j+1]+mx[1][i+1][j]+mx[2][i-1][j];

		chmax(res,max(tmp,tmp2));
	}
	cout<<res<<endl;



	return 0;
}