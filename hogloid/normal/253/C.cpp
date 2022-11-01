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
int n;
int wid[105];
int cost[105][100005];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	REP(i,n) cin>>wid[i];
	
	memset(cost,-1,sizeof(cost));
	
	pi p,p2;cin>>p.fr>>p.sc>>p2.fr>>p2.sc;
	--p.fr;--p.sc;
	--p2.fr;--p2.sc;

	queue<pi>q;q.push(p);cost[p.fr][p.sc]=0;
	while(!q.empty()){
		pi cur=q.front();q.pop();
		REP(i,4){
			int px=cur.sc+dx[i],py=cur.fr+dy[i];
			if(px<0 || py<0 || py>=n || px>wid[cur.fr]) continue;
			if(px>wid[py]) px=wid[py];
			if(cost[py][px]==-1){
				cost[py][px]=cost[cur.fr][cur.sc]+1;
				q.push(mp(py,px));
			}
		}
	}
	printf("%d\n",cost[p2.fr][p2.sc]);
	return 0;
}