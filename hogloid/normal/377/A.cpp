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
int k;
char buf[505][505];
int S=0;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void dfs(int y,int x){
	buf[y][x]='$';
	--S;
	REP(d,4){
		int px=x+dx[d],py=y+dy[d];
		if(px<0 || py<0 || px>=w || py>=h || buf[py][px]!='.' || S<=0) continue;
		dfs(py,px);
	}
}

int main(){
	cin>>h>>w>>k;
	REP(i,h) scanf("%s",buf[i]);

	REP(i,h) REP(j,w) if(buf[i][j]=='.') ++S;
	S-=k;
	
	dump(S);
	REP(i,h) REP(j,w) if(buf[i][j]=='.'){
		dfs(i,j);
		goto exi;
	}
exi:;

	REP(i,h) REP(j,w){
		if(buf[i][j]=='$') buf[i][j]='.';
		else if(buf[i][j]=='.') buf[i][j]='X';
	}

	REP(i,h) printf("%s\n",buf[i]);


	


	return 0;
}