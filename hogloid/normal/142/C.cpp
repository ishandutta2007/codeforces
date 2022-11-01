#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int shape[4][3][3]={
	{{1,1,1},{0,1,0},{0,1,0}},
	{{0,0,1},{1,1,1},{0,0,1}},
	{{0,1,0},{0,1,0},{1,1,1}},
	{{1,0,0},{1,1,1},{1,0,0}}
};
int buf[10][10];
int ans,res[10][10];
int putted,cur[10][10];
int w,h;
void dfs(int x,int y){
	if(x>=w){
		x=0;++y;
	}
	int rest=0;
	REP(i,h) REP(j,w) if(cur[i][j]==0 && mp(i,j)>=mp(y,x)) ++rest;
	if(putted+rest/5<=ans) return;
	if(y==h){
		if(ans<putted){
			ans=putted;
			REP(i,h) REP(j,w) res[i][j]=cur[i][j];
		}
		return;
	}
	int suc=0;
	if(x<w-2 && y<h-2){
		REP(i,4){
			int failed=0;
			REP(j,3) REP(k,3) if(shape[i][j][k]){
				if(cur[y+k][x+j]){
					failed=1;break;
				}
			}
			if(failed) continue;
			++putted;
			suc=1;
			REP(j,3) REP(k,3) if(shape[i][j][k]) cur[y+k][x+j]=putted;
			dfs(x+1,y);
			--putted;
			REP(j,3) REP(k,3) if(shape[i][j][k]) cur[y+k][x+j]=0;
		}
	}
	dfs(x+1,y);
}
int main(){
	scanf("%d%d",&h,&w);
	ans=putted=0;
	dfs(0,0);
	printf("%d\n",ans);
	REP(i,h){
		REP(j,w){
			if(res[i][j]) putchar('A'+res[i][j]-1);
			else putchar('.');
		}
		putchar('\n');
	}
	return 0;
}