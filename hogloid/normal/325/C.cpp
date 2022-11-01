#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =314000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int m,n;

vector<int> split[100005];

int worth[100005];
vector<int> list[100005];

int okcnt[100005];

static const int MAX_N = 100005;
vector<pi> G[MAX_N],rG[MAX_N];

int mini[100005],maxi[100005];



int done[100005];
int cost[100005];

int flag[100005];
void dfs(int v){
	flag[v]=1;
	maxi[v]=0;
	REP(i,split[v].size()){
		int id=split[v][i];
		
		int inf=0,sum=worth[id];
		int fail=0;
		REP(j,list[id].size()){
			int to=list[id][j];
			if(done[to]==0) fail=1;
			if(flag[to]==1) inf=1;
			else{
				if(flag[to]==0) dfs(to);
				if(maxi[to]==-2) inf=1;
				sum+=maxi[to];
				chmin(sum,INF);
			}
		}
		if(fail) continue;
		if(inf){
			maxi[v]=-2;break;
		}
		chmax(maxi[v],sum);
	}
	flag[v]=2;
}



int main(){
	cin>>m>>n;
	REP(i,m){
		int id,l;
		scanf("%d%d",&id,&l);--id;
		split[id].pb(i);
		REP(j,l){
			int to;scanf("%d",&to);
			if(to!=-1) list[i].pb(to-1);
			else ++worth[i];
		}
		REP(j,list[i].size()){
			int to=list[i][j];
			G[id].pb(mp(to,worth[i]));
			rG[to].pb(mp(id,i));
		}
	}
	REP(i,n){
		maxi[i]=INF+1;
		mini[i]=INF;
	}


	priority_queue<pi,vector<pi>,greater<pi> >pq;
	REP(i,n) {
		REP(j,split[i].size()) if(list[split[i][j]].empty()){
			chmin(mini[i],worth[split[i][j]]);
			pq.push(mp(worth[split[i][j]],i));
		}
	}
	memset(okcnt,0,sizeof(okcnt));
	while(!pq.empty()){
		pi cur=pq.top();pq.pop();

		if(done[cur.sc]) continue;
		done[cur.sc]=1;
		REP(i,rG[cur.sc].size()){
			pi& e=rG[cur.sc][i];

			cost[e.sc]+=cur.fr;
			chmin(cost[e.sc],INF);
			++okcnt[e.sc];
			if(okcnt[e.sc]==list[e.sc].size()){
				chmin(mini[e.fr],cost[e.sc]+worth[e.sc]);
				pq.push(mp(cost[e.sc]+worth[e.sc],e.fr));
			}
		}
	}


	REP(i,n) if(maxi[i]==INF+1) dfs(i);

	REP(i,n){
		if(!done[i]) puts("-1 -1");
		else printf("%d %d\n",mini[i],maxi[i]);
	}

	return 0;
}