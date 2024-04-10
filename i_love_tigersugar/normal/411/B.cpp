#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
int blk[MAX];
int x[MAX][MAX];
bool mem[MAX];
vector<int> use[MAX];
int n,m,k;
void process(void) {
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&x[i][j]);
    FOR(i,1,m) {
        REP(j,k+1) use[j].clear();
        FOR(j,1,n) if (blk[j]==0) use[x[j][i]].push_back(j);
        FOR(j,1,k) if (use[j].size()>1) mem[j]=true;
        FOR(j,1,k) if (mem[j]) FORE(it,use[j]) if (blk[*it]==0) blk[*it]=i;
    }
    FOR(i,1,n) printf("%d\n",blk[i]);
}
int main(void) {
    process();
    return 0;
}