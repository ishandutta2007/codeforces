#include<bits/stdc++.h>
#define MAX   5000500
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int fact[MAX];
bool notPrime[MAX];
void prepare(void) {
    REP(i,2) notPrime[i]=true;
    FOR(i,2,MAX-1) if (!notPrime[i]) {
        for (int j=2*i;j<MAX;j=j+i) notPrime[j]=true;
        int mul=i;
        while (true) {
            for (int j=mul;j<MAX;j=j+mul) fact[j]++;
            if (1LL*mul*i>=MAX) break;
            mul*=i;
        }
    }
    FOR(i,1,MAX-1) fact[i]+=fact[i-1];
}
void process(void) {
    int t;
    scanf("%d",&t);
    REP(love,t) {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",fact[a]-fact[b]);
    }
}
int main(void) {
    prepare();
    process();
    return 0;
}