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
queue<pi> q;
int main(){
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&buf[i][j]);
	REP(i,n) REP(j,n) sum[i+1][j+1]=buf[i][j];
	REP(i,n) REP(j,n) sum[i+2][j+1]+=sum[i+1][j+1];
	REP(i,n) REP(j,n) sum[i+1][j+2]+=sum[i+1][j+1];
	REP(i,n) REP(j,n){
		int right=j+6,top=i+6,bottom=i-6,left=j-6;
		right=min(right,n-1);
		top=min(top,n-1);
		left=max(left,0);
		bottom=max(bottom,0);

		int whole=(right-left+1)*(top-bottom+1),differ=sum[top+1][right+1]-sum[bottom][right+1]-
								sum[top+1][left]+sum[bottom][left];
		double rate=differ/(double)whole;
		if(rate>=0.6) buf[i][j]=1;
		else buf[i][j]=0;
	}
			
	int cir=0,sq=0;
	int id=2,cnt2=0;
	REP(i,n) REP(j,n) if(buf[i][j]==1){
		q.push(mp(i,j));
		buf[i][j]=id;
		int left=j,right=j,top=i,bottom=i;
		int cnt=0;
		while(!q.empty()){
			pi cur=q.front();q.pop();
			++cnt;
			left=min(left,cur.sc);
			right=max(right,cur.sc);
			top=max(top,cur.fr);
			bottom=min(bottom,cur.fr);
			for(int k=-2;k<=2;++k) for(int l=-2;l<=2;++l){
				int px=cur.sc+k,py=cur.fr+l;
				if(px<0 || py<0 || px>=n || py>=n || buf[py][px]!=1) continue;
				buf[py][px]=id;
				q.push(mp(py,px));
			}
		}
		int flag=0;
		double cx=(left+right)/2.0,cy=(top+bottom)/2.0;
		double len=0;
		for(int k=left;k<=right;++k) for(int l=bottom;l<=top;++l){
			if(buf[l][k]==id){
				len=max(len,sqrt((double)SPR(cx-k)+SPR(cy-l)));
			}
		}
		int left2=cx-len*1.6,right2=cx+len*1.6,top2=cy+len*1.6,bottom2=cy-len*1.6;
		len*=0.9;

		for(int k=left2;k<=right2;++k) for(int l=bottom2;l<=top2;++l){ 
			double tmp=sqrt((double)SPR(cx-k)+SPR(cy-l));
			if(tmp<len && (k<0 || k>=n || l<0 || l>=n || buf[l][k]!=id)){
				++flag;
			}
		}
		double rate=(double)flag/cnt;
		dump(rate);
		if(rate<=0.01) ++cir;
		else ++sq;
		++id;
	}

	printf("%d %d\n",cir,sq);
	return 0;
}