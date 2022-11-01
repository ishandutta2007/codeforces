#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
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

int n,sx,sy;
int buf[505][505];
string res;

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
string dir[]={
	"D","R","U","L"};
void dfs(int x,int y){
	if(buf[y][x]==0) res+="1";
	buf[y][x]=2;
	REP(d,4){
		int px=x+dx[d],py=y+dy[d];
		if(px<0 || py<0 || px>=n || py>=n || buf[py][px]>=2) continue;
		
		int ok=0;
		REPN(i,n,1){
			int px2=x+dx[d]*i,py2=y+dy[d]*i;
			if(px2<0 || py2<0 || px2>=n || py2>=n) break;
			if(buf[py2][px2]==1 || buf[py2][px2]==2){
				ok=1;break;
			}
		}
		if(!ok) continue;
		res+=dir[d];
		dfs(px,py);
		res+=dir[(d+2)%4];
	}
	buf[y][x]=3;
	res+="2";
}




int main(){
	cin>>n>>sy>>sx;
	--sy;--sx;
	REP(i,n) REP(j,n) scanf("%d",&buf[i][j]);
	
	dfs(sx,sy);
	REP(i,n) REP(j,n) if(buf[i][j]==1){
		puts("NO");
		return 0;
	}
	puts("YES");
	cout<<res<<endl;

	return 0;
}