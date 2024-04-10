#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<vector>
#include<sstream>
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


static const int MAX_V=300;		
int V;		

struct edge{
	int to,cap,cost,rev;
	edge(int st,int sc,int sco,int sr){
		to=st;cap=sc;cost=sco;rev=sr;
	}
};
vector<edge> g[MAX_V];
int h[MAX_V],dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,int cost){
	g[from].pb(edge(to,cap,cost,g[to].size()));
	g[to].pb(edge(from,0,-cost,g[from].size()-1));
}

int min_cost_flow(int s,int t,int f){
	int res=0;
	fill(h,h+V,0);
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

int n,m;
int ar[255],wei[255],doubling[255];
vector<string> ans;
int isfree[30];
map<int,int> use;
void ins(int id,int num){
	stringstream ss;ss<<(char)('a'+id);
	ss<<'=';ss<<num;
	ans.pb(ss.str());
}
void pr(int id){
	stringstream ss;ss<<"print(";
	ss<<(char)('a'+id);
	ss<<')';
	ans.pb(ss.str());
}
bool isflowing(int i){
	int s=i+1,to=-1;
	REPN(j,n,i+1) if(ar[j]==ar[i]){
		to=j;
		break;
	}
	if(to==-1) return false;
	else{
		REP(j,g[s].size()){
			edge& e=g[s][j];
			if(e.to==to){
				if(e.cap==1) return false;
				return true;
			}
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	REP(i,n) cin>>ar[i];
	int cnt=0;
	REP(i,n){
		int j=i;
		for(j=i;j<n && ar[i]==ar[j];++j) ++doubling[cnt];
		++cnt;
		i=j-1;
	}

	n=unique(ar,ar+n)-ar;
	REP(i,n) wei[i]=__builtin_popcount(ar[i]);
	int res=0;
	REP(i,n){
		res+=wei[i];
		REPN(j,n,i+1) if(ar[i]==ar[j]){
			add_edge(i+1,j,1,-wei[i]+32*(j-i-1));
			break;
		}
		if(i<n-1) add_edge(i,i+1,INF,32);
	}
	int S=n+2,T=n+3;
	add_edge(S,0,INF,0);
	add_edge(n-1,T,INF,0);

	V=n+4;

	int cost=min_cost_flow(S,T,m-1);
	cost-=32*(m-1)*(n-1);

	res+=cost;
	REP(i,30) isfree[i]=1;

	REP(i,n){
		if(use[ar[i]]==0){
			if(isflowing(i)){
				REP(j,m) if(isfree[j]){
					use[ar[i]]=j+1;
					isfree[j]=0;
					ins(j,ar[i]);
					break;
				}
				REP(j,doubling[i]) pr(use[ar[i]]-1);
			}else{
				REP(j,m) if(isfree[j]){
					ins(j,ar[i]);
					REP(k,doubling[i]) pr(j);
					break;
				}
			}
		}else{
			REP(j,doubling[i]) pr(use[ar[i]]-1);
			if(isflowing(i)==false){
				isfree[use[ar[i]]-1]=1;
				use[ar[i]]=0;
			}
		}
	}
	printf("%d %d\n",(int)ans.size(),res);
	REP(i,ans.size()) printf("%s\n",ans[i].c_str());
	return 0;
}