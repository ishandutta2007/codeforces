#include<bits/stdc++.h>
#define MAX   3333
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int a[MAX],n;
void process(void) {
    scanf("%d",&n);
    REP(i,n) scanf("%d",&a[i]);
    printf("%d\n",n);
    REP(i,n) {
        int id=i;
        FOR(j,i,n-1) if (a[j]<a[id]) id=j;
        swap(a[i],a[id]);
        printf("%d %d\n",i,id);
    }
}
int main(void) {
    process();
    return 0;
}