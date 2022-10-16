#include<bits/stdc++.h>
#define MAX   500500
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
void myAssert(bool a) {
    while (!a) cerr<<"XXX"<<endl;
}
struct Edge {
    int u,v;
    bool used;
    Edge() {
        u=v=used=0;
    }
    Edge(int _u,int _v) {
        u=_u;v=_v;
        used=false;
    }
    int other(int x) const {
        assert(u==x || v==x);
        return (u^v^x);
    }
};
struct Circle {
    vector<int> edge;
    bool visited;
    Circle() {
        edge.clear();
        visited=false;
    }
};
Edge edge[MAX];
int deg[MAX];
vector<int> remEdge[MAX];
vector<int> remNode;
vector<Circle> circle;
vector<pair<int,int> > circlePass[MAX];
vector<int> eulerPath;
int n,m,fstNode;
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        deg[u]++;
        deg[v]++;
        edge[i]=Edge(u,v);
    }
}
void addMoreEdge(void) {
    vector<int> oddNode;
    FOR(i,1,n) if (deg[i]%2==1) oddNode.push_back(i);
    REP(i,oddNode.size()) if (i%2==0) {
        edge[++m]=Edge(oddNode[i],oddNode[i+1]);
        deg[oddNode[i]]++;
        deg[oddNode[i+1]]++;
    }
    while (m%2==1) edge[++m]=Edge(1,1);
    FOR(i,1,m) {
        int u=edge[i].u;
        int v=edge[i].v;
        remEdge[u].push_back(i);
        remEdge[v].push_back(i);
        //printf("Edge %d is %d - %d\n",i,u,v);
    }
    FOR(i,1,n) remNode.push_back(i);
}
int getEdge(int u) {
    while (!remEdge[u].empty()) {
        if (edge[remEdge[u].back()].used) remEdge[u].pop_back();
        else return (remEdge[u].back());
    }
    return (-1);
}
int getNode(void) {
    while (!remNode.empty()) {
        if (getEdge(remNode.back())<0) remNode.pop_back();
        else return (remNode.back());
    }
    return (-1);
}
void buildCircle(int s) {
    int id=circle.size();
    circle.push_back(Circle());
    int u=s;
    while (true) {
        int edgeID=getEdge(u);
        //printf("Edge from %d is %d\n",u,edgeID);
        if (edgeID<0) break;
        circlePass[u].push_back(make_pair(id,(int)circle.back().edge.size()));
        circle.back().edge.push_back(edgeID);
        edge[edgeID].used=true;
        u=edge[edgeID].other(u);
    }
    /*printf("BuildCircle: %d\n",(int)circle.size()-1);
    FORE(it,circle.back().edge) printf("%d ",*it); printf("\n");*/
}
pair<int,int> getCircle(int u) {
    while (!circlePass[u].empty()) {
        if (circle[circlePass[u].back().fi].visited) circlePass[u].pop_back();
        else return (circlePass[u].back());
    }
    return (make_pair(-1,-1));
}
void joinCircle(int id,int s,int edgeID) {
    //printf("Join circle %d, start at %d, edge %d\n",id,s,edgeID);
    circle[id].visited=true;
    int u=s;
    REP(love,circle[id].edge.size()) {
        while (true) {
            pair<int,int> tmp=getCircle(u);
            if (tmp.fi<0) break;
            joinCircle(tmp.fi,u,tmp.se);
        }
        if (eulerPath.empty()) fstNode=u;
        eulerPath.push_back(circle[id].edge[edgeID]);
        u=edge[circle[id].edge[edgeID]].other(u);
        edgeID=(edgeID+1)%circle[id].edge.size();
    }
}
void process(void) {
    while (true) {
        int u=getNode();
        if (u<0) break;
        buildCircle(u);
    }
    pair<int,int> fstCircle=getCircle(1);
    joinCircle(fstCircle.fi,1,fstCircle.se);
    assert((int)eulerPath.size()==m);
    printf("%d\n",(int)eulerPath.size());
    int u=fstNode;
    REP(i,eulerPath.size()) {
        int id=eulerPath[i];
        int v=edge[id].other(u);
        if (i%2==0) printf("%d %d\n",u,v);
        else printf("%d %d\n",v,u);
        u=v;
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    loadGraph();
    addMoreEdge();
    process();
    return 0;
}