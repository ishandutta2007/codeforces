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
int n,t;
int buf[2][200][200];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main(){
	scanf("%d%d",&n,&t);
	
	buf[0][100][100]=n;
	bool changed=true;
	int cur=0,nxt=1;

	int tim=0;
	int minx=100;
	REP(hoge,27065){
		++tim;

		for(int i=minx-2;i<=200-minx+2;++i) for(int j=99;j<=200-minx+2;++j){
			if(buf[cur][i][j]>=4){
				minx=min(minx,i);
				REP(d,4) ++buf[nxt][i+dy[d]][j+dx[d]];
				buf[nxt][i][j]+=buf[cur][i][j]-4;
			}else buf[nxt][i][j]+=buf[cur][i][j];
		}
		for(int i=minx-2;i<=200-minx+2;++i){
			for(int j=99;j<=200-minx+2;++j){
				buf[cur][i][j]=0;
			}
			buf[nxt][i][99]=buf[nxt][i][101];
			buf[nxt][i][98]=0;
		}

		swap(cur,nxt);
	}
	dump(minx);
	
	while(t--){
		int x,y;scanf("%d%d",&x,&y);
		if(x<0) x*=-1;
		x+=100;
		y+=100;

		if(x<0 || y<0 || x>=200 || y>=200) puts("0");
		else printf("%d\n",buf[cur][y][x]);
	}


	return 0;
}