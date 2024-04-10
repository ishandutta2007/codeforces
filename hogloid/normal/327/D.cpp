#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;

int h,w;
char s[505][505];
int vis[505][505];

pair<pi,int>res[1000000];
int rcnt;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void dfs(int y,int x,int in=0){
	vis[y][x]=1;
	res[rcnt++]=mp(mp(y,x),0);
	REP(i,4){
		int px=x+dx[i],py=y+dy[i];
		if(px<0 || py<0 || px>=w || py>=h || vis[py][px] || s[py][px]=='#') continue;
		dfs(py,px);
	}
	if(!in){
		res[rcnt++]=mp(mp(y,x),2);
		res[rcnt++]=mp(mp(y,x),1);
	}
}

int main(){
	cin>>h>>w;
	REP(i,h) scanf("%s",s[i]);
	
	REP(i,h) REP(j,w) if(s[i][j]=='.' && !vis[i][j]){
		dfs(i,j,1);
	}

	cout<<rcnt<<endl;
	REP(i,rcnt){
		char c;
		if(res[i].sc==0) c='B';
		else if(res[i].sc==1) c='R';
		else c='D';
		printf("%c %d %d\n",c,res[i].fr.fr+1,res[i].fr.sc+1);
	}



	return 0;
}