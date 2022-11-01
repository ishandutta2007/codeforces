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
#define REPL(ar,len,k) k=lower_bound(ar,ar+len,k)-ar
int n;
pair<pi,pi> rect[10];
int xzip[25],yzip[25],nx,ny;

int area[25][25];
int main(){
	cin>>n;
	REP(i,n){
		cin>>rect[i].fr.fr>>rect[i].fr.sc>>rect[i].sc.fr>>rect[i].sc.sc;
		xzip[nx++]=rect[i].fr.fr;
		xzip[nx++]=rect[i].sc.fr;
		yzip[ny++]=rect[i].fr.sc;
		yzip[ny++]=rect[i].sc.sc;
	}
	sort(xzip,xzip+nx);
	sort(yzip,yzip+ny);
	nx=unique(xzip,xzip+nx)-xzip;
	ny=unique(yzip,yzip+ny)-yzip;

	REP(i,n){
		REPL(xzip,nx,rect[i].fr.fr);
		REPL(xzip,nx,rect[i].sc.fr);
		REPL(yzip,ny,rect[i].fr.sc);
		REPL(yzip,ny,rect[i].sc.sc);
	}

	REP(i,n){
		REPN(j,rect[i].sc.sc,rect[i].fr.sc) REPN(k,rect[i].sc.fr,rect[i].fr.fr){
			area[j][k]=1;
		}
	}
	
	int fail=0;
	REP(i,ny-1) REP(j,nx-1) if(area[i][j]==0) fail=1;
	if(fail || xzip[nx-1]-xzip[0]!=yzip[ny-1]-yzip[0]) puts("NO");
	else puts("YES");




	return 0;
}