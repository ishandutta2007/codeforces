#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int INF=(int)1e9+7;
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
class MaxFlowMinCost {
	private:
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
	public:
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
	void addedge(int u,int v,int ca,int co) {
		g[u].push_back(e.size());
		e.push_back(edge(u,v,ca,co));
		g[v].push_back(e.size());
		e.push_back(edge(v,u,0,-co));
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
	int maxflow(int s,int t,int limcost) {
		int totflow=0;
		while (FordBellman(s,t)) {
			int delta;
			if (d[t]==0) delta=INF; else delta=limcost/d[t];
			for (int u=t;u!=s;u=e[tr[u]].from) minimize(delta,e[tr[u]].residual());
			if (delta==0) return (totflow);
			for (int u=t;u!=s;u=e[tr[u]].from) {
				e[tr[u]].flow+=delta;
				e[tr[u]^1].flow-=delta;				
			}
			limcost-=delta*d[t];
			totflow+=delta;
		}
		return (totflow);
	}
};
MaxFlowMinCost g;
int n,k;
void process(void) {
	scanf("%d",&n);
	scanf("%d",&k);
	g=MaxFlowMinCost(n);
	FOR(i,1,n) FOR(j,1,n) {
		int t;
		scanf("%d",&t);
		if (t>0) {
			g.addedge(i,j,t,0);
			g.addedge(i,j,k,1);
		}
	}
	printf("%d",g.maxflow(1,n,k));
}
int main(void) {
	process();
	return 0;
}