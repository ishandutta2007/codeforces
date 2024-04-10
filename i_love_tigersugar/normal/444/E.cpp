//This solution is based on subscriber's solution
#include<bits/stdc++.h>
#define MAX   3333
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
struct edge {
    int u,v,c;
    edge() {
        u=v=c=0;
    }
    void input(void) {
        scanf("%d%d%d",&u,&v,&c);
    }
    bool operator < (const edge &x) const {
        return (c<x.c);
    }
};
edge e[MAX];
int al[MAX],sz[MAX];
int n,sum;
bool ok;
int find(int x) {
    if (sz[x]<0) return (x);
    sz[x]=find(sz[x]);
    return (sz[x]);
}
void join(int a,int b) {
    int x=find(a);
    int y=find(b);
    if (x==y) return;
    sz[x]+=sz[y];
    al[x]+=al[y];
    sz[y]=x;
    if (al[x]-sz[x]>sum) ok=false;
}
void loadtree(void) {
    scanf("%d",&n);
    REP(i,n-1) e[i].input();
    sort(e,e+n-1);
    FOR(i,1,n) {
        scanf("%d",&al[i]);
        sz[i]=-1;
        sum+=al[i];
    }
}
void process(void) {
    if (n==1) {
        printf("0");
        return;
    }
    int ans=e[0].c;
    ok=true;
    REP(i,n-1) {
        if (i>0 && e[i].c==e[i-1].c) continue;
        int j=i;
        while (j<n-1 && e[j].c==e[i].c) {
            join(e[j].u,e[j].v);
            j++;
        }
        if (ok && j<n-1) ans=e[j].c;
    }
    printf("%d",ans);
}
int main(void) {
    loadtree();
    process();
    return 0;
}