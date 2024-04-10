#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
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
static const int INF =1100000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,m;
vector<pi> g[100005];
vector<int> wait[100005],ok[100005];;
int adv[100005];
int cost[100005];
int main(){
	cin>>n>>m;
	REP(i,m){
		int a,b,c;cin>>a>>b>>c;
		--a;--b;
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
	}
	REP(i,n){
		int a;cin>>a;
		REP(j,a){
			int b;cin>>b;
			wait[i].pb(b);
		}
	}
	REP(i,n) cost[i]=INF;
	priority_queue<pi,vector<pi>,greater<pi> >pq;pq.push(mp(0,0));
	cost[0]=0;
	while(!pq.empty()){
		pi cur=pq.top();pq.pop();
		if(cost[cur.sc]<cur.fr) continue;
		while(binary_search(ALL(wait[cur.sc]),cur.fr)) ++cur.fr;
		REP(i,g[cur.sc].size()){
			pi& e=g[cur.sc][i];
			if(cost[e.fr]<=cur.fr+e.sc) continue;
			cost[e.fr]=cur.fr+e.sc;
			pq.push(mp(cost[e.fr],e.fr));
		}
	}
	if(cost[n-1]>=INF) cost[n-1]=-1;
	printf("%d\n",cost[n-1]);
	return 0;
}