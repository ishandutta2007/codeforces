#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<list>
#include<cstdio>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#define REP(num,num2) for(int num=0;num<(int)num2;++num)
#define REPN(num,num2,init) for(int num=init;num<(int)num2;++num)
#define ITR(x) __typeof((x).begin())
#define FOR(itr,data) for(ITR(data) itr=(data).begin();itr!=(data).end();++itr)
#define ALL(typ) (typ).begin(),(typ).end()
#define SPR(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz size()
#define INF ((int)1e9)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef long long int lint;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vp;
typedef pair<int,int> pi;
const double PI  = acos(-1.0);
template<class T> void debug(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
int zip[2005];
int n,k;
pair<pi,int> range[1005];
static const int MAX_V=2010;		//TO BE SPECIFIED


struct edge{
	int to,cap,cost,rev;
	int id;
	edge(int st,int sc,int sco,int sr,int sid=-1){
		to=st;cap=sc;cost=sco;rev=sr;id=sid;
	}
};
vector<edge> g[MAX_V];
int h[MAX_V],dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,int cost,int id=-1){
	g[from].pb(edge(to,cap,cost,g[to].size(),id));
	g[to].pb(edge(from,0,-cost,g[from].size()-1));
}
int used[MAX_V];
int V;		// THE NUMBER OF VERTICES
int min_cost_flow(int s,int t,int f){
	int res=0;
	fill(h,h+V,INF);
	while(f>0){
		priority_queue<pi,vector<pi>,greater<pi> >pq;pq.push(mp(0,s));
		fill(dist,dist+V,INF);
		dist[s]=0;
		while(!pq.empty()){
			pi cur=pq.top();pq.pop();
			if(dist[cur.sc]<cur.fr) continue;
			REP(i,g[cur.sc].size()){
				edge& e=g[cur.sc][i];
				if(e.cap>0 && dist[e.to]>cur.fr+e.cost+h[cur.sc]-h[e.to]){
					dist[e.to]=cur.fr+e.cost+h[cur.sc]-h[e.to];
					prevv[e.to]=cur.sc;
					preve[e.to]=i;
					pq.push(mp(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==INF){
			return -1;
		}
		for(int v=0;v<V;++v) h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,g[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge& e=g[prevv[v]][preve[v]];
			e.cap-=d;
			g[v][e.rev].cap+=d;
		}
	}
	return res;
}



int main(){
	scanf("%d%d",&n,&k);
	REP(i,n){
		int s,t,c;scanf("%d%d%d",&s,&t,&c);
		t=s+t;
		range[i]=mp(mp(s,t),c);
		zip[i*2]=s;
		zip[i*2+1]=t;
	}
	sort(zip,zip+n*2);
	int zn=unique(zip,zip+n*2)-zip;
	REP(i,n) range[i].fr.fr=lower_bound(zip,zip+zn,range[i].fr.fr)-zip,
		range[i].fr.sc=lower_bound(zip,zip+zn,range[i].fr.sc)-zip;
	int m=zn;
	int s=m,t=s+1;
	add_edge(s,0,k,0);
	add_edge(m-1,t,k,0);
	V=m+2;
	REP(i,m-1){
		add_edge(i,i+1,INF,0);
	}
	int res=0;
	REP(i,n){
		add_edge(range[i].fr.sc,range[i].fr.fr,1,range[i].sc,i);
		add_edge(s,range[i].fr.sc,1,0);
		add_edge(range[i].fr.fr,t,1,0);
		res-=range[i].sc;
	}
	res+=min_cost_flow(s,t,k+n);
	REP(i,V) REP(j,g[i].size()){
		edge& e=g[i][j];
		if(e.cap==0 && e.id!=-1) used[e.id]=1;
	}

	REP(i,n) printf("%d%c",used[i]^1,i==n-1?'\n':' ');
	return 0;
}