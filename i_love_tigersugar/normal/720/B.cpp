#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
class DisjointSet {
	private:
	vector<int> label; //label[x] stores the root of x if x is not root, otherwise it stores -(size of x's set).
	public:
	DisjointSet(){}
	DisjointSet(int n) {
		label.assign(n+7,-1); //label should contains at least n+1 elements, as x is 1-indexed.
		//At first, each node is a seperate set of size 1.
	}
	int find(int x) { //find the root of set which contains x.
		if (label[x]<0) return (x); //x is root iff label[x] is negative.
		label[x]=find(label[x]);
		return (label[x]); //find the root of x by recursion.
	}
	bool join(int a,int b) { // join the sets which contains a and b. Return false iff a and b are already in the same set.
		int x=find(a);
		int y=find(b);
		if (x==y) return (false); //A set contains both a and b.
		if (label[x]>label[y]) swap(x,y); //label[x]>label[y] means size(x)<size(y).
		//We speed up the disjoint set by joinning the smaller set to the bigger set
		label[x]+=label[y];
		label[y]=x; //Update the label of x and y.
		return (true);
	}
	int getSize(int x) { //return the size of set which contains x.
		return (-label[find(x)]);
	}
};
struct Edge {
    int u,v,c;
    Edge() {
        u=v=c=0;
    }
    Edge(int _u,int _v,int _c) {
        u=_u;v=_v;c=_c;
    }
    int other(int x) const {
        assert(u==x || v==x);
        return (u^v^x);
    }
};
//For graph
vector<Edge> edge;
vector<int> adj[MAX];
int low[MAX],num[MAX],par[MAX],cnt,n;
bool vst[MAX];
stack<int> st;
//For colorSet
int numSet;
bool special[MAX],checkedSet[MAX];
vector<int> atSet[MAX];
vector<int> colorSet[MAX];
//For colorSetComponent
bool isRoot[MAX];
int colorRoot[MAX];
int numColorInComp[MAX],maxEdgeInComp[MAX];
void loadGraph(void) {
    int m; scanf("%d%d",&n,&m); assert(m<MAX);
    REP(love,m) {
        int u,v,c; scanf("%d%d%d",&u,&v,&c);
        adj[u].push_back(edge.size());
        adj[v].push_back(edge.size());
        edge.push_back(Edge(u,v,c));
    }
}
void findNewComp(int edgeID) {
    numSet++;
    while (true) {
        int id=st.top(); st.pop();
        colorSet[numSet].push_back(edge[id].c);
        if (id==edgeID) return;
    }
}
void dfs(int u) {
    vst[u]=true;
    num[u]=++cnt;
    low[u]=num[u];
    FORE(it,adj[u]) {
        int v=edge[*it].other(u);
        if (!vst[v]) {
            st.push(*it);
            par[v]=u;
            dfs(v);
            if (low[v]>=num[u]) findNewComp(*it);
            minimize(low[u],low[v]);
        } else if (par[u]!=v && num[v]<num[u]) {
            st.push(*it);
            minimize(low[u],num[v]);
        }
    }
}
void findColorSet(void) {
    FOR(i,1,n) if (!vst[i]) dfs(i);
    FOR(i,1,numSet) FORE(it,colorSet[i])
        atSet[*it].push_back(i);
//    printf("Found %d sets\n",numSet);
//    FOR(i,1,numSet) {
//        printf("Set %d: ",i);
//        FORE(it,colorSet[i]) printf("%d ",*it); printf("\n");
//    }
}
void findSpecialColor(void) {
    queue<int> q;
    FOR(i,1,numSet) if (colorSet[i].size()==1) {
        int color=colorSet[i][0];
        special[color]=true;
        checkedSet[i]=true;
        q.push(color);
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        FORE(it,atSet[u]) if (!checkedSet[*it]) {
            checkedSet[*it]=true;
            FORE(jt,colorSet[*it]) if (!special[*jt]) {
                special[*jt]=true;
                q.push(*jt);
            }
        }
    }
}
void processOtherColor(void) {
    DisjointSet dsu(numSet);
    REP(i,MAX) if (!special[i]) FORE(it,atSet[i])
        dsu.join(atSet[i].front(),*it);
    REP(i,MAX) if (!special[i] && !atSet[i].empty()) colorRoot[i]=dsu.find(atSet[i].front());
    REP(i,MAX) if (!special[i] && !atSet[i].empty())
        numColorInComp[colorRoot[i]]++;
    FOR(i,1,numSet) if (!checkedSet[i]) {
        int root=dsu.find(i);
        maxEdgeInComp[root]+=colorSet[i].size()-1;
    }
    FOR(i,1,numSet) if (!checkedSet[i]) isRoot[i]=dsu.find(i)==i;
}
void process(void) {
    findColorSet();
    findSpecialColor();
    processOtherColor();
    int res=0;
    REP(i,MAX) if (special[i]) res++;
    FOR(i,1,numSet) if (!checkedSet[i] && isRoot[i]) res+=min(maxEdgeInComp[i],numColorInComp[i]);
    printf("%d\n",res);
}
int main(void) {
    loadGraph();
    process();
    return 0;
}