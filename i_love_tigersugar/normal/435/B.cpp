#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
char a[33];
int n,k;
void process(void) {
    scanf("%s%d",a+1,&k);
    n=strlen(a+1);
    FOR(i,1,n) {
        int id=i;
        FOR(j,i,n) if (a[j]>a[id] && j-i<=k) id=j;
        FORD(j,id,i+1) swap(a[j],a[j-1]);
        k-=id-i;
    }
    printf("%s",a+1);
}
int main(void) {
    process();
    return 0;
}