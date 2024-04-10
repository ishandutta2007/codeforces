#include<bits/stdc++.h>
#define MAX   100100
#define MAXT   303
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int f[MAX][MAXT],minf[MAX][MAXT];
vector<int> id[MAX];
int a[MAX],b[MAX];
int n,m,s,e;
void init(void) {
    scanf("%d%d%d%d",&n,&m,&s,&e);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,m) {
        scanf("%d",&b[i]);
        id[b[i]].push_back(i);
    }
    REP(i,MAX) id[i].push_back(m+1);
}
void optimize(void) {
    FOR(i,1,n) {
        assert(!id[a[i]].empty());
        f[i][1]=id[a[i]][0];
        if (i==1) minf[i][1]=f[i][1]; else minf[i][1]=min(minf[i-1][1],f[i][1]);
    }
    FOR(j,2,s/e) {
        f[1][j]=m+1;
        minf[1][j]=m+1;
        FOR(i,2,n) {
            if (minf[i-1][j-1]>m) f[i][j]=m+1;
            else {
                int t=upper_bound(id[a[i]].begin(),id[a[i]].end(),minf[i-1][j-1])-id[a[i]].begin();
                if (t<id[a[i]].size()) f[i][j]=id[a[i]][t]; else f[i][j]=m+1;
            }
            minf[i][j]=min(minf[i-1][j],f[i][j]);
        }
    }
}
void trace(void) {
    int res=0;
    FOR(i,1,n) FOR(j,1,s/e) if (f[i][j]<=m && j*e+i+f[i][j]<=s && res<j) res=j;
    printf("%d",res);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    optimize();
    trace();
    return 0;
}