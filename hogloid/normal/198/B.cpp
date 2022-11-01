#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
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
int n,k;
char buf[3][100010];
int cost[3][100010];
bool solve(){
	scanf("%d%d",&n,&k);
	REP(i,2) scanf("%s",buf[i]);
	memset(cost,-1,sizeof(cost));
	cost[0][0]=0;
	queue<pi>q;q.push(mp(0,0));
	while(!q.empty()){
		pi cur=q.front();q.pop();
		if(cost[cur.fr][cur.sc]>cur.sc) continue;
		if(cur.sc>=n-k) return true;
		if(buf[cur.fr][cur.sc+1]!='X' && cost[cur.fr][cur.sc+1]==-1){
			cost[cur.fr][cur.sc+1]=cost[cur.fr][cur.sc]+1;
			q.push(mp(cur.fr,cur.sc+1));
		}
		if(buf[cur.fr^1][cur.sc+k]!='X' && cost[cur.fr^1][cur.sc+k]==-1){
			cost[cur.fr^1][cur.sc+k]=cost[cur.fr][cur.sc]+1;
			q.push(mp(cur.fr^1,cur.sc+k));
		}
		if(cur.sc>0 && buf[cur.fr][cur.sc-1]!='X' && cost[cur.fr][cur.sc-1]==-1){
			cost[cur.fr][cur.sc-1]=cost[cur.fr][cur.sc]+1;
			q.push(mp(cur.fr,cur.sc-1));
		}
	}
	return false;
}
int main(){
	if(solve()) puts("YES");
	else puts("NO");
	return 0;
}