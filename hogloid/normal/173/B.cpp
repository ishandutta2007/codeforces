#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef long double ld;
typedef pair<int,int> pi;
int h,w;
char buf[1005][1005];
int cost[1005][1005][2];
int main(){
	scanf("%d%d",&h,&w);
	REP(i,h) scanf("%s",buf[i]);
	REP(i,h) REP(j,w) cost[i][j][0]=cost[i][j][1]=INF;
	priority_queue<pair<pi,pi>,vector<pair<pi,pi> >,greater<pair<pi,pi> > >pq;
	pq.push(mp(mp(0,0),mp(h-1,w-1)));
	while(!pq.empty()){
		pair<pi,pi>cur=pq.top();pq.pop();
		if(cost[cur.sc.fr][cur.sc.sc][cur.fr.sc]<cur.fr.fr) continue;
		if(buf[cur.sc.fr][cur.sc.sc]=='#'){
			if(cost[cur.sc.fr][cur.sc.sc][cur.fr.sc^1]>cur.fr.fr+1){
				cost[cur.sc.fr][cur.sc.sc][cur.fr.sc^1]=cur.fr.fr+1;
				pq.push(mp(mp(cur.fr.fr+1,cur.fr.sc^1),cur.sc));
			}
		}
		REP(i,4){
			int px=cur.sc.sc+dx[i],py=cur.sc.fr+dy[i];
			if(px<0 || py<0 || px>=w || py>=h) continue;
			if((i&1)^cur.fr.sc^1) continue;
			if(cost[py][px][cur.fr.sc]>cur.fr.fr){
				cost[py][px][cur.fr.sc]=cur.fr.fr;
				pq.push(mp(mp(cur.fr.fr,cur.fr.sc),mp(py,px)));
			}
		}
	}
	if(cost[0][0][0]==INF) puts("-1");
	else printf("%d\n",cost[0][0][0]);
	return 0;
}