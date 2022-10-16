#include<bits/stdc++.h>
#define MAX   3030
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long ll;
bool haveRoad[MAX][MAX];
vector<int> toNode[MAX],fromNode[MAX];
int n,m;
void loadgraph(void) {
    scanf("%d%d",&n,&m);
    REP(zz,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        fromNode[u].push_back(v);
        toNode[v].push_back(u);
        haveRoad[u][v]=true;
    }
}
int countSame(int u,int v) {
    int res=0;
    if (fromNode[u].size()<=toNode[v].size()) {
        FORE(it,fromNode[u]) if (haveRoad[*it][v]) res++;
    } else {
        FORE(it,toNode[v]) if (haveRoad[u][*it]) res++;
    }
    return (res);
}
ll comb(int x) {
    return (1LL*x*(x-1)/2);
}
void process(void) {
    ll res=0;
    FOR(i,1,n) FOR(j,1,n) if (i!=j) res+=comb(countSame(i,j));
    cout<<res;
}
int main(void) {
    loadgraph();
    process();
    return 0;
}