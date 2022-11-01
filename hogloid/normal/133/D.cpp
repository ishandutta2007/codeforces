#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
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
int w,h,n;
char buf[55][55];
pi moveTo[55][55][4][2];
int state[55][55][4][2];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int main(){
	cin>>h>>n;
	REP(i,h) cin>>buf[i];
	w=strlen(buf[0]);
	REP(i,h) REP(j,w) REP(k,4) REP(l,2){
		int cx=j,cy=i;
		while(1){
			int px=cx+dx[k],py=cy+dy[k];
			if(px<0 || py<0 || px>=w || py>=h || buf[py][px]!=buf[cy][cx]) break;
			cx=px;cy=py;
		}
		int add;
		if(l==0) add=3;
		else add=1;
		int k2=(k+add)%4;
		int px,py;
		while(1){
			px=cx+dx[k2],py=cy+dy[k2];
			if(px<0 || py<0 || px>=w || py>=h || buf[py][px]!=buf[cy][cx]) break;
			cx=px;cy=py;
		}
		px=cx+dx[k];py=cy+dy[k];
		if(px<0 || py<0 || px>=w || py>=h || buf[py][px]=='0'){
			state[i][j][k][l]=1;
			moveTo[i][j][k][l]=mp(cy,cx);
		}else{
			moveTo[i][j][k][l]=mp(py,px);
		}
	}
	int cx=0,cy=0,dir=0,hand=0;
	REP(hoge,n){
		pi nxt=moveTo[cy][cx][dir][hand];
		int flag=state[cy][cx][dir][hand];
		cy=nxt.fr;cx=nxt.sc;
		if(flag){
			if(hand==0) hand=1;
			else{
				hand=0;
				dir=(dir+1)%4;
			}
		}
	}
	printf("%c\n",buf[cy][cx]);

	return 0;
}