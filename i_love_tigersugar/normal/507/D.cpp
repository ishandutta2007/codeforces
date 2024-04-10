#include<bits/stdc++.h>
#define MAXN   1111
#define MAXD   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int n,d,mod;
int f[MAXN][MAXD][2][2];
int pw10[MAXN];
void add(int &x,const int &y) {
    x+=y;
    if (x>=mod) x-=mod;
}
void process(void) {
    cin>>n>>d>>mod;
    pw10[0]=1;
    FOR(i,1,n) pw10[i]=pw10[i-1]*10%d;
    f[0][0][0][1]=1;
    REP(dig,n) REP(cur,d) REP(ok,2) REP(ze,2) if (f[dig][cur][ok][ze]>0)
        FOR(chs,dig==n-1?1:0,9) {
            int nextMod=(chs*pw10[dig]+cur)%d;
            int nextZe=ze && (chs==0);
            add(f[dig+1][nextMod][ok || (!nextZe && nextMod==0)][nextZe],f[dig][cur][ok][ze]);
        }
    int res=0;
    REP(cur,d) add(res,f[n][cur][1][0]);
    cout<<res<<endl;
}
int main(void) {
    process();
    return 0;
}