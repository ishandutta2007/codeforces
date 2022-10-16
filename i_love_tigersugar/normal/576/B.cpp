#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const char yes[]="YES";
const char no[]="NO";
int p[MAX],n,cyc[MAX];
bool vst[MAX],type[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&p[i]);
}
void specialCase(void) {
    FOR(i,1,n) if (p[i]==i) {
        printf("%s\n",yes);
        FOR(j,1,n) if (j!=i) printf("%d %d\n",i,j);
        exit(0);
    }
}
int findCycle(int s) {
    int u=s;
    int res=1;
    while (true) {
        vst[u]=true;
        u=p[u];
        if (u==s) break;
        res++;
    }
    return (res);
}
void fillCycle(int s,int v) {
    int u=s;
    bool mode=0;
    while (true) {
        cyc[u]=v;
        type[u]=mode;
        mode^=1;
        u=p[u];
        if (u==s) break;
    }
}
void process(void) {
    FOR(i,1,n) if (!vst[i]) fillCycle(i,findCycle(i));
    FOR(i,1,n) if (cyc[i]%2==1) {
        printf("%s\n",no);
        return;
    }
    FOR(i,1,n) if (cyc[i]==2) {
        int x=i;
        int y=p[i];
        printf("%s\n",yes);
        printf("%d %d\n",x,y);
        FOR(j,1,n) if (j!=x && j!=y) printf("%d %d\n",type[j]?x:y,j);
        exit(0);
    }
    printf("%s\n",no);
}
int main(void) {
    init();
    specialCase();
    process();
    return 0;
}