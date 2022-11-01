#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
char buf[55][55];
int dx[4]={0,1,0,-1},dy[]={1,0,-1,0};
char tmp[55][55];
void dfs(int i,int j){
	tmp[i][j]='.';
	REP(k,4){
		int px=j+dx[k],py=i+dy[k];
		if(px<0 || py<0 || px>=w || py>=h || tmp[py][px]=='.') continue;
		dfs(py,px);
	}
}
bool div(){
	memcpy(tmp,buf,sizeof(buf));
	int isle=0;
	REP(i,h) REP(j,w) if(tmp[i][j]=='#'){
		++isle;
		dfs(i,j);
	}
	return (isle!=1);
}
int main(){
	scanf("%d%d",&h,&w);
	REP(i,h) scanf("%s",buf[i]);
	int ns=0;
	REP(i,h) REP(j,w) if(buf[i][j]=='#') ++ns;
	if(ns<=2) puts("-1");
	else{
		int suc=0;
		REP(i,h) REP(j,w) if(buf[i][j]=='#'){
			buf[i][j]='.';
			if(div()) suc=1;
			buf[i][j]='#';
		}
		if(suc) puts("1");
		else puts("2");
	}


	return 0;
}