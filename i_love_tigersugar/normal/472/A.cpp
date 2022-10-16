#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
bool notprime[MAX];
void eratosthene(void) {
    FOR(i,2,MAX-1) if (!notprime[i])
        for (int j=2*i;j<MAX;j=j+i) notprime[j]=true;
}
int main(void) {
    eratosthene();
    int n;
    scanf("%d",&n);
    FOR(i,2,n) if (notprime[i] && notprime[n-i]) {
        printf("%d %d",i,n-i);
        return 0;
    }
    return 1;
}