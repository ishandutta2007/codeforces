#include<bits/stdc++.h>
#define MAX   111
#define REP(i,n) for (int i=0;i<(n);i=i+1)
bool ex[MAX][MAX];
int n;
void init(void) {
    scanf("%d",&n);
    REP(i,n) {
        int t;
        scanf("%d",&t);
        REP(j,t) {
            int v;
            scanf("%d",&v);
            ex[i][v]=true;
        }
    }
}
bool issub(int x,int y) {
    if (x==y) return (true);
    REP(i,MAX) if (!ex[x][i] && ex[y][i]) return (true);
    return (false);
}
bool canwin(int x) {
    REP(i,n) if (!issub(x,i)) return (false);
    return (true);
}
void process(void) {
    REP(i,n) if (canwin(i)) printf("YES\n"); else printf("NO\n");
}
int main(void) {
    init();
    process();
    return 0;
}