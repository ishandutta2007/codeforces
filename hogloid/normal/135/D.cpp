#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
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
int h,w;
char buf[1005][1005];
int vis[1005][1005];
int mark[1005][1005],deg[1005][1005],id[1005][1005];
pi task[1000005];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
struct uf{
	int par[1000005];
	void init(int n){
		REP(i,n) par[i]=-1;
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		par[a]=b;
	}
};
uf u;
void around(int y,int x){
	REP(d,4){
		int px=x+dx[d],py=y+dy[d];
		if(px>=0 && py>=0 && px<w && py<h && buf[py][px]=='1'){
			u.unite(id[y][x],id[py][px]);
			++deg[py][px];
		}
	}
}
int sum[1005][1005];
int main(){
	scanf("%d%d",&h,&w);
	REP(i,h) scanf("%s",buf[i]);
	REP(i,h) REP(j,w) sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+(buf[i][j]=='1');

	
	int cnt=0;
	int ans=0;
	REP(i,h-1) REP(j,w-1) if(sum[i+2][j+2]-sum[i+2][j]-sum[i][j+2]+sum[i][j]==4){
		ans=4;
	}
	REP(i,h) REP(j,w) if(buf[i][j]=='0' && vis[i][j]==0){
		++cnt;
		int fail=0;
		queue<pi> q;q.push(mp(i,j));
		vis[i][j]=cnt;

		int n=0;
		while(!q.empty()){
			 pi cur=q.front();q.pop();
			 REPN(dx,2,-1) REPN(dy,2,-1){
				 int px=cur.sc+dx,py=cur.fr+dy;
				 if(px<0 || py<0 || px>=w || py>=h){
					 fail=1;continue;
				 }
				 if(vis[py][px]==cnt) continue;
				 if(buf[py][px]=='1'){
					 if(mark[py][px]!=cnt){
						id[py][px]=n;
						task[n++]=mp(py,px);
						deg[py][px]=0;
					 	mark[py][px]=cnt;
					 }
					 continue;
				}
				q.push(mp(py,px));
				vis[py][px]=cnt;
			 }
		}
		if(fail) continue;
		u.init(n);
		REP(k,n) around(task[k].fr,task[k].sc);
		
		REP(k,n) if(deg[task[k].fr][task[k].sc]!=2) fail=1;
		
		int r=u.root(0);
		REP(k,n) if(u.root(k)!=r) fail=1;

		if(!fail){
			ans=max(ans,n);
		}
	}
	printf("%d\n",ans);





	return 0;
}