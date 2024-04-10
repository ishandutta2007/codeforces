#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod=(int)1e9+7;
int comb[MAX][MAX];
int n;
void precount(void) {
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
}
void process(void) {
    int s=0;
    int res=1;
    scanf("%d",&n);
    REP(love,n) {
        int t;
        scanf("%d",&t);
        res=1LL*res*comb[s][s+t-1]%mod;
        s+=t;
    }
    printf("%d\n",res);
}
int main(void) {
    precount();
    process();
    return 0;
}