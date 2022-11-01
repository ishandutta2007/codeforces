#define DEB

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

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}
const lint INF=1e18;
int n,m,k;
typedef pair<pair<lint,int>,int> stat;
vector<pair<int,pi> >g[100005];

pair<lint,int> cost[100005];
int main(){
	cin>>n>>m>>k;
	REP(i,m){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		--a;--b;
		g[a].pb(mp(b,mp(c,0)));
		g[b].pb(mp(a,mp(c,0)));
	}
	REP(i,k){
		int s,y;scanf("%d%d",&s,&y);
		--s;
		g[0].pb(mp(s,mp(y,1)));
		g[s].pb(mp(0,mp(y,1)));
	}
	
	REP(i,n) cost[i]=mp(INF,0);
	priority_queue<stat ,vector<stat>,greater<stat> >pq;
	pq.push(mp(mp(0,0),0));
	cost[0]=mp(0,0);

	while(!pq.empty()){
		stat cur=pq.top();pq.pop();
		if(cost[cur.sc]<cur.fr) continue;
		int v=cur.sc;
		REP(i,g[v].size()){
			pair<int,pi>& e=g[v][i];
			if(cost[e.fr]<=mp(cur.fr.fr+e.sc.fr,e.sc.sc)) continue;
			
			cost[e.fr]=mp(cur.fr.fr+e.sc.fr,e.sc.sc);
			pq.push(mp(cost[e.fr],e.fr));
		}
	}

	int res=0;
	REP(i,n) if(cost[i].sc==1) ++res;

	res=k-res;
	cout<<res<<endl;



	return 0;
}