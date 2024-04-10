#include<bits/stdc++.h>
#define MAX   1010
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int INF=(int)1e9+7;
typedef pair<int,int> ii;
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
class MaxFlowMinCost {
	public:
	struct edge {
		int from,to,capa,flow,cost;
		edge() {
			from=0;to=0;capa=0;flow=0;cost=0;	
		}
		edge(int u,int v,int ca,int co) {
			from=u;to=v;capa=ca;flow=0;cost=co;
		}
		int residual(void) const {
			return (capa-flow);
		}
	};
	vector<vector<int> > g;
	vector<edge> e;
	vector<int> d,tr;
	int n;
	MaxFlowMinCost() {
		n=0;
	}
	MaxFlowMinCost(int n) {
		this->n=n;
		g.assign(n+7,vector<int>());
		e.clear();
		d=vector<int>(n+7);
		tr=vector<int>(n+7);
	}
	int addedge(int u,int v,int ca,int co) {
		g[u].push_back(e.size());
		e.push_back(edge(u,v,ca,co));
		g[v].push_back(e.size());
		e.push_back(edge(v,u,0,-co));
		return (e.size()-2);
	}
	bool FordBellman(int s,int t) {
		FOR(i,1,n) {
			d[i]=INF;
			tr[i]=-1;			
		}
		vector<bool> inq=vector<bool>(n+7,false);
		queue<int> q;
		while (!q.empty()) q.pop();
		q.push(s);d[s]=0;inq[s]=true;
		while (!q.empty()) {
			int u=q.front();q.pop();inq[u]=false;
			FORE(it,g[u]) if (e[*it].residual()>0) {
				int v=e[*it].to;
				if (d[v]>d[u]+e[*it].cost) {
					d[v]=d[u]+e[*it].cost;
					tr[v]=*it;
					if (!inq[v]) {
						q.push(v);
						inq[v]=true;
					}
				}		
			}
		}
		return (d[t]<INF);
	}
	ii getflow(int s,int t) {
		int totflow=0;
		int totcost=0;
		while (FordBellman(s,t)) {
			int delta=INF;
			for (int u=t;u!=s;u=e[tr[u]].from) minimize(delta,e[tr[u]].residual());
			for (int u=t;u!=s;u=e[tr[u]].from) {
				e[tr[u]].flow+=delta;
				e[tr[u]^1].flow-=delta;
			}
			totflow+=delta;
			totcost+=delta*d[t];
		}
		return (ii(totflow,totcost));
	}
};
int n,k;
int a[MAX],b[MAX],c[MAX],id[MAX];
vector<ii> v;
MaxFlowMinCost g;
void init(void) {
	scanf("%d",&n);
	scanf("%d",&k);
	FOR(i,1,n) {
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		scanf("%d",&c[i]);
		v.push_back(ii(a[i],i));
		v.push_back(ii(a[i]+b[i],-i));
	}
	sort(v.begin(),v.end());
	g=MaxFlowMinCost(2*n+2);
	FOR(i,1,2*n+1) g.addedge(i,i+1,k,0);
	FOR(i,1,n) {
		int x=lower_bound(v.begin(),v.end(),ii(a[i],i))-v.begin()+2;
		int y=lower_bound(v.begin(),v.end(),ii(a[i]+b[i],-i))-v.begin()+2;
		id[i]=g.addedge(x,y,1,-c[i]);
	}
}
void process(void) {
	g.getflow(1,2*n+2);
	FOR(i,1,n) {
		printf("%d",g.e[id[i]].flow>0);
		if (i<n) printf(" ");
	}
}
int main(void) {
	init();
	process();
	return 0;
}