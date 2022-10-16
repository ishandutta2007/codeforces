#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
using namespace std;
int n,k,a,m,x[MAX];
void init(void) {
    scanf("%d%d%d%d",&n,&k,&a,&m);
    FOR(i,1,m) scanf("%d",&x[i]);
}
bool ok(int t) {
    vector<int> pos;
    FOR(i,1,t) pos.push_back(x[i]);
    pos.push_back(0);
    pos.push_back(n+1);
    sort(ALL(pos));
    int cnt=0;
    REP(i,(int)pos.size()-1) cnt+=(pos[i+1]-pos[i])/(a+1);
    return (cnt>=k);
}
int process(void) {
    if (ok(m)) return (-1);
    int L=0;
    int R=m;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (!ok(L)?L:R);
        int M=(L+R)>>1;
        if (!ok(M)) R=M; else L=M+1;
    }
}
int main(void) {
    init();
    printf("%d\n",process());
    return 0;
}