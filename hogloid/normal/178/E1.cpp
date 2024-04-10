#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
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
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
int buf[2005][2005];
int sum[2005][2005];
queue<pi> q;
int main(){
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&buf[i][j]);
	int cir=0,sq=0;
	REP(i,n) REP(j,n) if(buf[i][j]==1){
		q.push(mp(i,j));
		int left=j,right=j,top=i,bottom=i;
		while(!q.empty()){
			pi cur=q.front();q.pop();
			left=min(left,cur.sc);
			right=max(right,cur.sc);
			top=max(top,cur.fr);
			bottom=max(bottom,cur.fr);
			REP(k,4){
				int px=cur.sc+dx[k],py=cur.fr+dy[k];
				if(px<0 || py<0 || px>=n || py>=n || buf[py][px]!=1) continue;
				buf[py][px]=2;
				q.push(mp(py,px));
			}
		}
		int flag=0;
		for(int k=left;k<=right;++k) for(int l=bottom;l<=top;++l){
			if(buf[l][k]!=2){
				flag=1;
				goto exi;
			}
		}
		exi:;
		if(flag) ++cir;
		else ++sq;
	}
	printf("%d %d\n",cir,sq);
	return 0;
}