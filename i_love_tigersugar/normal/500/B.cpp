#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
#define MAX   333
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
class DisjointSet {
    private:
    vector<int> lab;
    public:
    DisjointSet(){}
    DisjointSet(int n) {
        lab.assign(n+7,-1);
    }
    int find(int x) {
        if (lab[x]<0) return (x);
        lab[x]=find(lab[x]);
        return (lab[x]);
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
};
char canSwap[MAX][MAX];
int sta[MAX],compID[MAX],res[MAX];
priority_queue<int,vector<int>,greater<int> > choose[MAX];
int n,nComp;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&sta[i]);
    FOR(i,1,n) scanf("%s",canSwap[i]+1);
}
void process(void) {
    DisjointSet dsu(n);
    FOR(i,1,n) FOR(j,1,n) if (canSwap[i][j]=='1') dsu.join(i,j);
    FOR(i,1,n) if (dsu.find(i)==i) compID[i]=++nComp;
    FOR(i,1,n) if (dsu.find(i)!=i) compID[i]=compID[dsu.find(i)];
    FOR(i,1,n) choose[compID[i]].push(sta[i]);
    FOR(i,1,n) {
        res[i]=choose[compID[i]].top();
        choose[compID[i]].pop();
    }
    FOR(i,1,n) printf("%d ",res[i]); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}