#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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
int h,w,d;
char buf[1005][1005];
vector<pi> rat;
int cost[1005][1005],idef[1005][1005],idef2[1005][1005],idef3[1005][1005];

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};


pi q[1000005];

int cnt1=1,cnt2=1;
pi bfs2(int sy,int sx,int id,int id_){
	int st=0,en=0;
	q[en++]=mp(sy,sx);
	cost[sy][sx]=0;
	idef3[sy][sx]=id;
	
	while(st<en){
		pi cur=q[st++];
		if(cost[cur.fr][cur.sc]>=d) break;
		REP(d,4){
			int px=cur.sc+dx[d],py=cur.fr+dy[d];
			if(px<0 || py<0 || px>=w || py>=h || buf[py][px]=='X' ||
				idef3[py][px]==id) continue;
			cost[py][px]=cost[cur.fr][cur.sc]+1;
			idef3[py][px]=id;
			q[en++]=mp(py,px);
		}
	}

	int fail=0;
	REP(i,rat.size()) if(idef[rat[i].fr][rat[i].sc]!=id_ && idef3[rat[i].fr][rat[i].sc]!=id){
		fail=1;
		return mp(-1,-1);
	}
	return mp(sy,sx);
}

pi bfs(int sy,int sx,int id,int id_){
	int st=0,en=0;
	q[en++]=mp(sy,sx);
	cost[sy][sx]=0;
	idef2[sy][sx]=id;
	
	vector<pi> ok;
	while(st<en){
		pi cur=q[st++];
		if(cost[cur.fr][cur.sc]>d) break;
		ok.pb(cur);
		REP(d,4){
			int px=cur.sc+dx[d],py=cur.fr+dy[d];
			if(px<0 || py<0 || px>=w || py>=h || buf[py][px]=='X' ||
				idef2[py][px]==id) continue;
			cost[py][px]=cost[cur.fr][cur.sc]+1;
			idef2[py][px]=id;
			q[en++]=mp(py,px);
		}
	}
	REP(i,ok.size()){
		pi a=bfs2(ok[i].fr,ok[i].sc,cnt2++,id_);
		if(a.fr!=-1) return a;
	}
	return mp(-1,-1);
}


pi solve(int sy,int sx,int id){
	int st=0,en=0;
	q[en++]=mp(sy,sx);
	cost[sy][sx]=0;
	idef[sy][sx]=id;

	while(st<en){
		pi cur=q[st++];
		if(cost[cur.fr][cur.sc]>=d) break;
		REP(d,4){
			int px=cur.sc+dx[d],py=cur.fr+dy[d];
			if(px<0 || py<0 || px>=w || py>=h || buf[py][px]=='X' ||
				idef[py][px]==id) continue;
			cost[py][px]=cost[cur.fr][cur.sc]+1;
			idef[py][px]=id;
			q[en++]=mp(py,px);
		}
	}

	REP(i,rat.size()) if(idef[rat[i].fr][rat[i].sc]!=id){
		return bfs(rat[i].fr,rat[i].sc,cnt1++,id);
	}
	REP(i,h) REP(j,w) if(buf[i][j]!='X' && mp(i,j)!=mp(sy,sx)) return mp(i,j);
}




int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d",&h,&w,&d);
	REP(i,h) scanf("%s",buf[i]);
	REP(i,h) REP(j,w) if(buf[i][j]=='R') rat.pb(mp(i,j));
	
	memset(cost,-1,sizeof(cost));
	
	int st=0,en=0;
	q[en++]=rat[0];
	cost[rat[0].fr][rat[0].sc]=0;
	while(st<en){
		pi cur=q[st++];
		REP(d,4){
			int px=cur.sc+dx[d],py=cur.fr+dy[d];
			if(px<0 || py<0 || px>=w || py>=h || cost[py][px]!=-1 ||
				buf[py][px]=='X') continue;
			cost[py][px]=cost[cur.fr][cur.sc]+1;
			q[en++]=mp(py,px);
		}
	}
	vector<pi> st2;
	REP(i,h) REP(j,w) if(cost[i][j]<=d && cost[i][j]!=-1){
		st2.pb(mp(i,j));
	}
	memset(cost,-1,sizeof(cost));
	memset(idef,-1,sizeof(idef));


	REP(i,st2.size()){
		pi p=solve(st2[i].fr,st2[i].sc,i);
		if(p.fr!=-1){
			printf("%d %d %d %d\n",st2[i].fr+1,st2[i].sc+1,p.fr+1,p.sc+1);
			return 0;
		}
	}
	puts("-1");



	return 0;
}