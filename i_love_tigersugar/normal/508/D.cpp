#include<bits/stdc++.h>
#define MAXN   4040
#define MAXM   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int n=62*62;
const char yes[]="YES";
const char no[]="NO";
class DisjointSet {
    private:
    vector<int> lab;
    int find(int x) {
        return (lab[x]<0?x:lab[x]=find(lab[x]));
    }
    public:
    DisjointSet() {}
    DisjointSet(int n) {
        lab.assign(n+7,-1);
    }
    bool join(int a,int b) {
        int x=find(a);
        int y=find(b);
        if (x==y) return (false);
        if (lab[x]>lab[y]) swap(x,y);
        lab[x]+=lab[y];
        lab[y]=x;
        return (true);
    }
    bool sameSet(int u,int v) {
        return (find(u)==find(v));
    }
};
struct Edge {
    int from,to;
    bool used,fake;
    Edge() {
        from=to=0;
        used=fake=false;
    }
    Edge(int u,int v,bool f) {
        from=u;to=v;used=false;fake=f;
    }
};
string allChar;
map<string,int> strID;
string haveID[MAXN];
void precount(void) {
    FOR(i,'0','9') allChar.push_back(i);
    FOR(i,'A','Z') allChar.push_back(i);
    FOR(i,'a','z') allChar.push_back(i);
    int cnt=0;
    REP(i,allChar.size()) REP(j,allChar.size()) {
        string s;
        s.push_back(allChar[i]);
        s.push_back(allChar[j]);
        strID[s]=++cnt;
        haveID[cnt]=s;
    }
    assert(strID.size()==n);
}
Edge edge[MAXM];
int inDeg[MAXN],outDeg[MAXN];
vector<int> unusedEdge[MAXN];
vector<int> haveUnused;
vector<int> haveCircle[MAXN];
vector<vector<int> > circle;
vector<bool> visited;
vector<int> path;
int m;
void init(void) {
    cin>>m;
    REP(i,m) {
        string s;
        cin>>s;
        int u=strID[s.substr(0,2)];
        int v=strID[s.substr(1,2)];
        edge[i]=Edge(u,v,false);
        unusedEdge[u].push_back(i);
        outDeg[u]++;
        inDeg[v]++;
    }
}
void noAnswer(void) {
    printf("%s\n",no);
    exit(0);
}
void checkAnswer(void) {
    int inNode=-1;
    int outNode=-1;
    FOR(i,1,n) {
        if (inDeg[i]>outDeg[i]+1 || outDeg[i]>inDeg[i]+1) noAnswer();
        if (inDeg[i]==outDeg[i]+1) {
            if (inNode<0) inNode=i; else noAnswer();
        }
        if (outDeg[i]==inDeg[i]+1) {
            if (outNode<0) outNode=i; else noAnswer();
        }
    }
    DisjointSet dsu(n);
    REP(i,m) dsu.join(edge[i].from,edge[i].to);
    int nonZero=-1;
    FOR(i,1,n) if (outDeg[i]>0 || inDeg[i]>0) {
        if (nonZero<0) nonZero=i;
        else if (!dsu.sameSet(i,nonZero)) noAnswer();
    }
    if (inNode>=0) {
        edge[m]=Edge(inNode,outNode,true);
        unusedEdge[inNode].push_back(m);
        outDeg[inNode]++;
        inDeg[outNode]++;
    }
    FOR(i,1,n) haveUnused.push_back(i);
}
int getEdge(int u) {
    while (!unusedEdge[u].empty()) {
        int id=unusedEdge[u].back();
        if (!edge[id].used) return (id);
        else unusedEdge[u].pop_back();
    }
    return (-1);
}
int getNode(void) {
    while (!haveUnused.empty()) {
        int u=haveUnused.back();
        if (getEdge(u)>=0) return (u);
        else haveUnused.pop_back();
    }
    return (-1);
}
bool buildCircle(void) {
    int u=getNode();
    if (u<0) return (false);
    circle.push_back(vector<int>());
    visited.push_back(false);
    vector<int> &cur=circle.back();
    while (true) {
        haveCircle[u].push_back(circle.size()-1);
        int id=getEdge(u);
        if (id<0) return (true);
        cur.push_back(id);
        edge[id].used=true;
        u=edge[id].to;
    }
}
int getCircle(int u) {
    while (!haveCircle[u].empty()) {
        int id=haveCircle[u].back();
        if (!visited[id]) return (id);
        haveCircle[u].pop_back();
    }
    return (-1);
}
void joinPath(int s,int id) {
    assert(!visited[id]);
    visited[id]=true;
    int pos=0;
    if (s>=0) REP(i,circle[id].size()) if (edge[circle[id][i]].from==s) pos=i;
    REP(love,circle[id].size()) {
        int u=edge[circle[id][pos]].from;
        while (true) {
            int id=getCircle(u);
            if (id<0) break;
            joinPath(u,id);
        }
        path.push_back(circle[id][pos]);
        pos=(pos+1)%circle[id].size();
    }
}
bool found(const vector<int> &v,int x) {
    FORE(it,v) if (edge[*it].from==x) return (true);
    return (false);
}
void trace(void) {
    while (buildCircle());
    joinPath(-1,0);
    int id=0;
    assert(path.size()==m || path.size()==m+1);
    REP(i,path.size()) if (edge[path[i]].fake) id=(i+1)%path.size();
    printf("YES\n%s",haveID[edge[path[id]].from].c_str());
    REP(love,m) {
        int u=edge[path[id]].from;
        int v=edge[path[id]].to;
        printf("%c",haveID[edge[path[id]].to][1]);
        id=(id+1)%path.size();
    }
    printf("\n");
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    ios::sync_with_stdio(false);
    precount();
    init();
    checkAnswer();
    trace();
    return 0;
}