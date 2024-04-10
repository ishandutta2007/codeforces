/*#include<bits/stdc++.h>
#define MAX   1111
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
	    int ret=e.size();
		g[u].push_back(e.size());
		e.push_back(edge(u,v,ca,co));
		g[v].push_back(e.size());
		e.push_back(edge(v,u,0,-co));
		return (ret);
	}
	bool FordBellman(int s,int t) {
		FOR(i,1,n) {
			d[i]=INF;
			tr[i]=-1;
		}
		vector<bool> inq=vector<bool>(n+7,false);
		queue<int> q;
		while (!q.empty()) q.pop();
		q.push(s);inq[s]=true;d[s]=0;
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
MaxFlowMinCost G;
int c[MAX],p[MAX],s[MAX];
int id[MAX][MAX];
int n,m;
void loadgraph(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&c[i],&p[i]);
    scanf("%d",&m);
    FOR(i,1,m) scanf("%d",&s[i]);
    G=MaxFlowMinCost(m+n+3);
    FOR(i,1,n) FOR(j,1,m) if (c[i]<=s[j]) id[i][j]=G.addedge(i,n+j,1,-p[i]);
    FOR(i,1,n) G.addedge(m+n+1,i,1,0);
    FOR(i,1,m) G.addedge(n+i,m+n+2,1,0);
    G.addedge(m+n+1,m+n+2,n,0);
    G.addedge(m+n+3,m+n+1,n,0);
}
void trace(void) {
    vector<ii> v;
    int best=G.getflow(m+n+3,m+n+2).se;
    FOR(i,1,n) FOR(j,1,m) if (c[i]<=s[j] && G.e[id[i][j]].flow>0) v.push_back(ii(i,j));
    sort(v.begin(),v.end());
    printf("%d %d\n",v.size(),-best);
    FORE(it,v) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
    loadgraph();
    trace();
    return 0;
}*/
#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
struct user {
    int c,p,id;
    user() {
        c=p=id=0;
    }
    void input(int id) {
        this->id=id;
        scanf("%d%d",&c,&p);
    }
    bool operator < (const user &x) const {
        return (c<x.c);
    }
};
user a[MAX];
ii b[MAX];
int n,m;
int f[MAX][MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) a[i].input(i);
    scanf("%d",&m);
    FOR(i,1,m) {
        scanf("%d",&b[i].fi);
        b[i].se=i;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
}
void optimize(void) {
    FOR(i,1,n) FOR(j,1,m) {
        f[i][j]=max(f[i-1][j],f[i][j-1]);
        if (a[i].c<=b[j].fi) f[i][j]=max(f[i][j],f[i-1][j-1]+a[i].p);
    }
}
void trace(void) {
    vector<ii> v;
    int i=n,j=m;
    while (i>0 && j>0) {
        if (f[i][j]==f[i-1][j]) {
            i--;
            continue;
        }
        if (f[i][j]==f[i][j-1]) {
            j--;
            continue;
        }
        assert(a[i].c<=b[j].fi);
        v.push_back(ii(a[i].id,b[j].se));
        i--;j--;
    }
    printf("%d %d\n",v.size(),f[n][m]);
    sort(v.begin(),v.end());
    FORE(it,v) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
    init();
    optimize();
    trace();
    return 0;
}