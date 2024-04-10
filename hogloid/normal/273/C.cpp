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
int n,m;
vector<int> g[300005];
int bad[300005],col[300005];
int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	priority_queue<pi>pq;
	REP(i,n){
		bad[i]=g[i].size();
		pq.push(mp(bad[i],i));
	}
	while(!pq.empty()){
		pi cur=pq.top();pq.pop();
		int a=cur.sc,prev=cur.fr;
		if(prev!=bad[a]) continue;
		if(prev<=1) break;
		col[a]^=1;
		bad[a]=g[a].size()-prev;
		REP(i,g[a].size()){
			int to=g[a][i];
			if(col[to]==col[a])++bad[to];
			else --bad[to];
			pq.push(mp(bad[to],to));
		}
		pq.push(mp(bad[a],a));
	}
	REP(i,n) putchar(col[i]+'0');
	putchar('\n');
	return 0;
}