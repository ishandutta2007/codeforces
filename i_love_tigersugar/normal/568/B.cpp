#include<bits/stdc++.h>
#define MAX   4040
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod=(int)1e9+7;
int comb[MAX][MAX];
int f[MAX],numWay[MAX][MAX],sumWay[MAX];
void prepare(void) {
    REP(i,MAX) {
        comb[i][0]=0;
        comb[0][i]=1;
    }
    comb[0][0]=1;
    FOR(i,1,MAX-1) FOR(j,1,MAX-1) {
        if (i>j) comb[i][j]=0;
        if (i==j) comb[i][j]=1;
        if (i<j) comb[i][j]=(comb[i][j-1]+comb[i-1][j-1])%mod;
    }
    numWay[0][0]=1;
    FOR(i,1,MAX-1) FOR(j,1,i) numWay[i][j]=(numWay[i-1][j-1]+1LL*j*numWay[i-1][j])%mod;
    FOR(i,1,MAX-1) FOR(j,1,i) sumWay[i]=(sumWay[i]+numWay[i][j])%mod;
    FOR(i,1,MAX-1) {
        f[i]=1;
        FOR(j,1,i-1) f[i]=(f[i]+1LL*comb[j][i]*sumWay[j])%mod;
    }
}
int main(void) {
    prepare();
    int n;
    scanf("%d",&n);
    printf("%d\n",f[n]);
    return 0;
}