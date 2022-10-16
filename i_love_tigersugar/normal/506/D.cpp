#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
class DisjointSet {
    private:
    vector<int> lab;
    int find(int x) {
        if (lab[x]<0) return (x);
        lab[x]=find(lab[x]);
        return (lab[x]);
    }
    public:
    DisjointSet(){}
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
vector<pair<int,int> > edge[MAX];
vector<int> node[MAX];
vector<pair<int,int> > haveColor[MAX];
DisjointSet dsu[MAX];
map<pair<int,int>,int> result;
int n,m,q;
void loadGraph(void) {
    scanf("%d%d",&n,&m);
    REP(love,m) {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        if (u>v) swap(u,v);
        edge[c].push_back(make_pair(u,v));
        node[c].push_back(u);
        node[c].push_back(v);
    }
}
void prepare(void) {
    FOR(i,1,m) if (!edge[i].empty()) {
        sort(node[i].begin(),node[i].end());
        node[i].resize(unique(node[i].begin(),node[i].end())-node[i].begin());
        dsu[i]=DisjointSet(node[i].size());
        FORE(it,edge[i]) {
            int u=lower_bound(node[i].begin(),node[i].end(),it->fi)-node[i].begin()+1;
            int v=lower_bound(node[i].begin(),node[i].end(),it->se)-node[i].begin()+1;
            dsu[i].join(u,v);
        }
        REP(j,node[i].size()) haveColor[node[i][j]].push_back(make_pair(i,j+1));
    }
}
int answer(int u,int v) {
    if (u>v) return (answer(v,u));
    if (result.find(make_pair(u,v))!=result.end()) return (result[make_pair(u,v)]);
    int res=0;
    if (haveColor[u].size()<haveColor[v].size()) {
        FORE(it,haveColor[u]) {
            int c=it->fi;
            int pu=it->se;
            int pv=lower_bound(node[c].begin(),node[c].end(),v)-node[c].begin();
            if (pv<node[c].size() && node[c][pv]==v) pv++; else continue;
            if (dsu[c].sameSet(pu,pv)) res++;
        }
    } else {
        FORE(it,haveColor[v]) {
            int c=it->fi;
            int pv=it->se;
            int pu=lower_bound(node[c].begin(),node[c].end(),u)-node[c].begin();
            if (pu<node[c].size() && node[c][pu]==u) pu++; else continue;
            if (dsu[c].sameSet(pu,pv)) res++;
        }
    }
    return (result[make_pair(u,v)]=res);
}
void process(void) {
    scanf("%d",&q);
    REP(love,q) {
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",answer(u,v));
    }
}
int main(void) {
    loadGraph();
    prepare();
    process();
    return 0;
}