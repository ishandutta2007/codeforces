#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int a[MAX],n;
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) {
        if (i==1) printf("%d ",a[2]-a[1]);
        else if (i==n) printf("%d ",a[n]-a[n-1]);
        else printf("%d ",min(a[i]-a[i-1],a[i+1]-a[i]));
        printf("%d\n",max(a[i]-a[1],a[n]-a[i]));
    }
}
int main(void) {
    process();
    return 0;
}