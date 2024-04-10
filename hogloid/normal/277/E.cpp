#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
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



static const int MAX_V=1000;		
int V;		

struct edge{
	int to,cap;
	double cost;
	int rev;
	edge(int st,int sc,double sco,int sr){
		to=st;cap=sc;cost=sco;rev=sr;
	}
};
vector<edge> g[MAX_V];
double h[MAX_V];
double dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,double cost){
	g[from].pb(edge(to,cap,cost,g[to].size()));
	g[to].pb(edge(from,0,-cost,g[from].size()-1));
}

double min_cost_flow(int s,int t,int f){
	double res=0;
	fill(h,h+V,0);
	while(f>0){
		priority_queue<pair<double,int> ,vector<pair<double,int> >
				,greater<pair<double,int> > >pq;pq.push(mp(0,s));
		fill(dist,dist+V,INF);
		dist[s]=0;
		while(!pq.empty()){
			pair<double,int> cur=pq.top();pq.pop();
			if(dist[cur.sc]+1e-6<cur.fr) continue;
			REP(i,g[cur.sc].size()){
				edge& e=g[cur.sc][i];
				if(e.cap>0 && dist[e.to]>cur.fr+e.cost+h[cur.sc]-h[e.to]+1e-6){
					dist[e.to]=cur.fr+e.cost+h[cur.sc]-h[e.to];
					prevv[e.to]=cur.sc;
					preve[e.to]=i;
					pq.push(mp(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]>=INF-1){
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

int n;
pi p[405];


int main(){
	cin>>n;
	REP(i,n) cin>>p[i].fr>>p[i].sc;
	
	int S=n*2,T=n*2+1;
	V=T+1;
	REP(i,n) REP(j,n) if(p[i].sc>p[j].sc){
		double d=sqrt((double)(p[i].fr-p[j].fr)*(p[i].fr-p[j].fr)+(p[i].sc-p[j].sc)*
					(p[i].sc-p[j].sc));
		add_edge(j,i+n,1,d);
	}
	REP(i,n) add_edge(i+n,T,2,0);
	REP(i,n) add_edge(S,i,1,0);

	double c=min_cost_flow(S,T,n-1);

	if(c<0) puts("-1");
	else printf("%.10f\n",c);


	return 0;
}