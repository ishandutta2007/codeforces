#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
bool notPrime[MAX];
int n;
int pw(int x,int k) {
    int res=1;
    int mul=x;
    while (k>0) {
        if (k&1) res=1LL*res*mul%n;
        mul=1LL*mul*mul%n;
        k>>=1;
    }
    return (res);
}
void eratosthene(void) {
    REP(i,2) notPrime[i]=true;
    FOR(i,2,MAX-1) if (!notPrime[i]) for (int j=2*i;j<MAX;j=j+i) notPrime[j]=true;
}
void process(void) {
    scanf("%d",&n);
    if (n<=3) {
        printf("YES\n");
        FOR(i,1,n) printf("%d\n",i);
        return;
    }
    if (n==4) {
        printf("YES\n");
        printf("1\n3\n2\n4\n");
        return;
    }
    if (notPrime[n]) {
        printf("NO");
        return;
    }
    printf("YES\n");
    printf("1\n");
    FOR(i,2,n-1) printf("%d\n",1LL*i*pw(i-1,n-2)%n);
    printf("%d\n",n);
}
int main(void) {
    eratosthene();
    process();
    return 0;
}