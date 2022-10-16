#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
int a[MAX],prev[MAX],next[MAX];
int n,res;
inline void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    prev[1]=1;
    FOR(i,2,n) prev[i]=a[i]>a[i-1]?prev[i-1]+1:1;
    next[n]=1;
    FORD(i,n-1,1) next[i]=a[i]<a[i+1]?next[i+1]+1:1;
    FOR(i,1,n) {
        maximize(res,prev[i-1]+1);
        maximize(res,next[i+1]+1);
        if (1<i && i<n && a[i-1]+1<a[i+1]) maximize(res,prev[i-1]+next[i+1]+1);
    }
    printf("%d",res);
}
int main(void) {
    process();
    return 0;
}