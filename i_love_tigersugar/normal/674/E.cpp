#include<bits/stdc++.h>
#define MAX   500500
#define MAXL   115
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
double prob[MAX][MAXL+3];
int par[MAX];
int q;
void update(int cur) {
    double oldVal=prob[cur][0];
    prob[cur][0]*=0.5;
    double newVal=prob[cur][0];
    FOR(i,2,MAXL+1) {
        if (cur==1) return;
        cur=par[cur];
        double nextOldVal=prob[cur][i-1];
        prob[cur][i-1]/=(0.5+0.5*oldVal);
        prob[cur][i-1]*=(0.5+0.5*newVal);
        double nextNewVal=prob[cur][i-1];
        oldVal=nextOldVal;
        newVal=nextNewVal;
    }
}
double calc(int u) {
    double res=0.0;
    FOR(i,1,MAXL) res+=(prob[u][i]-prob[u][i-1])*i;
    return (res);
}
void process(void) {
    int n=1;
    FOR(i,0,MAXL) prob[1][i]=1.0;
    scanf("%d",&q);
    REP(love,q) {
        int t; scanf("%d",&t);
        if (t==1) {
            int p; scanf("%d",&p);
            par[++n]=p;
            FOR(i,0,MAXL) prob[n][i]=1.0;
            update(p);
//            printf("AFTER update %d\n",n);
//            FOR(i,1,n) {
//                printf("PROB of %d: ",i);
//                FOR(j,1,5) printf("%.3lf ",prob[i][j]); printf("\n");
//            }
        } else {
            int v; scanf("%d",&v);
            printf("%.11lf\n",calc(v));
        }
    }
}
int main(void) {
    process();
    return 0;
}