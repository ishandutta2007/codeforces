#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int h,w;
char buf[2000][2000];
pi pos[2000][2000];
int main(){
	scanf("%d%d",&h,&w);
	REP(i,h) scanf("%s",buf[i]);
	int sx,sy;
	REP(i,h) REP(j,w) if(buf[i][j]=='S'){
		sx=j;sy=i;
	}
	REP(i,h) REP(j,w) pos[i][j]=mp(INF,INF);
	queue<pi> q;q.push(mp(sy,sx));
	int flag=0;
	while(!q.empty()){
		pi cur=q.front();q.pop();
		REP(i,4){
			int px=cur.sc+dx[i],py=cur.fr+dy[i];
			int ppx=(px%w+w)%w,ppy=(py%h+h)%h;
			if(pos[ppy][ppx]==mp(py,px) || buf[ppy][ppx]=='#') continue;
			if(pos[ppy][ppx]!=mp(INF,INF)){
				puts("Yes");
				return 0;
			}
			pos[ppy][ppx]=mp(py,px);
			q.push(mp(py,px));
		}
	}
	puts("No");

	return 0;
}