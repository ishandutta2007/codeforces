#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int a[2207],n,k;
int main(void) {
    scanf("%d%d",&n,&k);
    REP(i,n) scanf("%d",&a[i]);
    sort(a,a+n,greater<int>());
    int res=0;
    REP(i,n) if (a[i]>0 && a[i]>=a[k-1]) res++;
    printf("%d\n",res);
    return 0;
}