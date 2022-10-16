#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
char adj[MAX][MAX];
int cur[MAX],goal[MAX];
bool chs[MAX];
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%s",adj[i]+1);
    FOR(i,1,n) scanf("%d",&goal[i]);
}
bool ok(void) {
    FOR(i,1,n) if (cur[i]==goal[i]) return (false);
    return (true);
}
void print(void) {
    int cnt=0;
    FOR(i,1,n) if (chs[i]) cnt++;
    printf("%d\n",cnt);
    FOR(i,1,n) if (chs[i]) printf("%d ",i); printf("\n");
    exit(0);
}
void invite(int u) {
    chs[u]=true;
    FOR(i,1,n) if (adj[u][i]=='1') cur[i]++;
}
void process(void) {
    while (!ok()) {
        FOR(i,1,n) if (cur[i]==goal[i]) invite(i);
    }
}
int main(void) {
    init();
    process();
    print();
    return 0;
}