#include<bits/stdc++.h>
#define MAX   33
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
int a[MAX];
double prob[MAX][MAX][2];
int n,m;
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
}
int afterRev(int l,int r,int p) {
    if (p<l || p>r) return (p);
    return (r+l-p);
}
void optimize(void) {
    FOR(i,1,n) FOR(j,1,n) prob[i][j][0]=i<j;
    int nWay=n*(n+1)/2;
    FOR(k,1,m) {
        int cur=k&1;
        int prev=cur^1;
        FOR(i,1,n) FOR(j,1,n) prob[i][j][cur]=0.0;
        FOR(i,1,n) FOR(j,1,n) if (i!=j)
            FOR(l,1,n) FOR(r,l,n) prob[i][j][cur]+=prob[afterRev(l,r,i)][afterRev(l,r,j)][prev]/nWay;
    }
    double res=0.0;
    FOR(i,1,n) FOR(j,1,n) if (a[i]>a[j]) res+=prob[i][j][m&1];
    printf("%.11lf\n",res);
}
int main(void) {
    init();
    optimize();
    return 0;
}