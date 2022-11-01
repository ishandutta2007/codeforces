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
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
char buf[10][10];
int able[105][10][10];
int main(){
	int n=8;
	REP(i,n) scanf("%s",buf[i]);

	able[0][n-1][0]=1;
	int ans=0;
	REP(i,105) REP(j,n) REP(k,n) if(able[i][j][k]){
		if(mp(j,k)==mp(0,n-1)) ans=1;
		REPN(dx,2,-1) REPN(dy,2,-1){
			int px=k+dx,py=j+dy;
			if(px<0 || py<0 || px>=n || py>=n) continue;
			if(py-i>=0 && buf[py-i][px]=='S') continue;
			if(py-i-1>=0 && buf[py-i-1][px]=='S') continue;
			able[i+1][py][px]=1;
		}
	}
	if(ans) puts("WIN");
	else puts("LOSE");
	
	return 0;
}