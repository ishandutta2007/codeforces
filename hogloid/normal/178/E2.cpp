#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define SPR(x) ((x)*(x))
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
double dst[4000005];
queue<pi> q;
int main(){
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&buf[i][j]);
	int cir=0,sq=0;
	int id=2;
	REP(i,n) REP(j,n) if(buf[i][j]==1){
		q.push(mp(i,j));
		buf[i][j]=id;
		int left=j,right=j,top=i,bottom=i;
		while(!q.empty()){
			pi cur=q.front();q.pop();
			left=min(left,cur.sc);
			right=max(right,cur.sc);
			top=max(top,cur.fr);
			bottom=min(bottom,cur.fr);
			REP(k,4){
				int px=cur.sc+dx[k],py=cur.fr+dy[k];
				if(px<0 || py<0 || px>=n || py>=n || buf[py][px]!=1) continue;
				buf[py][px]=id;
				q.push(mp(py,px));
			}
		}
		int flag=0;
		double cx=(left+right)/2.0,cy=(top+bottom)/2.0;
		double len=0;
		int cnt=0;
		for(int k=left;k<=right;++k) for(int l=bottom;l<=top;++l){
			if(buf[l][k]==id){
				len=max(len,sqrt((double)SPR(cx-k)+SPR(cy-l)));
			}
		}
		len*=0.9;
		for(int k=left-10;k<=right+10;++k) for(int l=bottom-10;l<=top+10;++l) 
		if(0<=k && k<n && 0<=l && l<n){
			double tmp=sqrt((double)SPR(cx-k)+SPR(cy-l));
			if(tmp<len && buf[l][k]!=id){
				flag=1;
			}
		}
		if(flag) ++sq;
		else ++cir;
		++id;
	}
	printf("%d %d\n",cir,sq);
	return 0;
}