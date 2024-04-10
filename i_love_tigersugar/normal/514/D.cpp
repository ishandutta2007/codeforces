#include<bits/stdc++.h>
#define MAXN   100100
#define MAXM   6
#define LOG   17
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
using namespace std;
int a[MAXM][MAXN];
int rmq[MAXM][MAXN][LOG+1];
int lg2[MAXN];
int n,m,lim;
void init(void) {
    scanf("%d%d%d",&n,&m,&lim);
    FOR(j,1,n) REP(i,m) scanf("%d",&a[i][j]);
}
void setupRMQ(void) {
    REP(k,m) {
        FOR(i,1,n) rmq[k][i][0]=a[k][i];
        FOR(j,1,LOG) FOR(i,1,n-MASK(j)+1) rmq[k][i][j]=max(rmq[k][i][j-1],rmq[k][i+MASK(j-1)][j-1]);
    }
    FOR(i,1,n) {
        while (MASK(lg2[i])<=i) lg2[i]++;
        lg2[i]--;
    }
}
int getMax(int t,int l,int r) {
    if (l>r) return (0);
    int k=lg2[r-l+1];
    return (max(rmq[t][l][k],rmq[t][r-MASK(k)+1][k]));
}
int sumMax(int l,int r) {
    if (l>r) return (0);
    int res=0;
    REP(j,m) res+=getMax(j,l,r);
    return (res);
}
int findRight(int i) {
    if (sumMax(i,i)>lim) return (i-1);
    if (sumMax(i,n)<=lim) return (n);
    int L=i;
    int R=n;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (sumMax(i,R)<=lim?R:L);
        int M=(L+R)>>1;
        if (sumMax(i,M)<=lim) L=M; else R=M-1;
    }
}
void process(void) {
    int L=1;
    int R=0;
    FOR(i,1,n) {
        int j=findRight(i);
        if (j<i) continue;
        if (j-i+1>R-L+1) {
            L=i;
            R=j;
        }
    }
    if (L>R) {
        REP(love,m) printf("0 "); printf("\n");
        return;
    }
    REP(i,m) printf("%d ",getMax(i,L,R)); printf("\n");
}
int main(void) {
    init();
    setupRMQ();
    process();
    return 0;
}