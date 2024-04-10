#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
const char yes[]="YES";
const char no[]="NO";
int a[MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void process(void) {
    if (n==1) {
        if (a[1]==1) printf("NO\n");
        else printf("YES\n0\n");
        return;
    }
    int lastZero=0;
    FORD(i,n,1) {
        if (a[i]==0) lastZero++;
        else break;
    }
    if (lastZero==0) {
        printf("NO\n");
        return;
    }
    if (lastZero==1) {
        printf("YES\n");
        FOR(i,1,n) {
            printf("%d",a[i]);
            if (i<n) printf("->"); else printf("\n");
        }
        return;
    }
    if (lastZero>=3) {
        printf("YES\n");
        FOR(i,1,n-3) printf("%d->",a[i]);
        printf("(0->0)->0\n");
        return;
    }
    int id=n-2;
    while (id>0 && a[id]==1) id--;
    if (id==0) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    FOR(i,1,id-1) printf("%d->",a[i]);
    printf("(0->(");
    FOR(i,id+1,n-1) {
        printf("%d",a[i]);
        if (i<n-1) printf("->");
        else printf("))");
    }
    printf("->0\n");
}
int main(void) {
    init();
    process();
    return 0;
}