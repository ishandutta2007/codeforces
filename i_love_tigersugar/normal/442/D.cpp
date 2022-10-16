//This solution is based on Egor's solution
#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int p[MAX],f[MAX],ch[MAX];
int n;
void process(void) {
    scanf("%d",&n);
    FOR(i,2,n+1) {
        int u,t;
        scanf("%d",&u);
        p[i]=u;
        u=i;
        t=1;
        while (u>1) {
            int v=p[u];
            if (f[v]<t) {
                f[v]=t;
                ch[v]=u;
            }
            else if (f[v]==t && ch[v]!=u) t++;
            else break;
            u=v;
        }
        if (i>2) printf(" ");
        printf("%d",f[1]);
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    process();
    return 0;
}