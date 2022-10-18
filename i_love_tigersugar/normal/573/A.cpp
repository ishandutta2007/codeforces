#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int a[MAX],n;
int main(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",&a[i]);
        while (a[i]%2==0) a[i]/=2;
        while (a[i]%3==0) a[i]/=3;
    }
    FOR(i,1,n) if (a[i]!=a[1]) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}