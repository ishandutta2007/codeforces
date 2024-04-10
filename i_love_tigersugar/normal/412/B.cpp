#include<bits/stdc++.h>
#define MAX   111
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int a[MAX];
int n,k;
int main(void) {
    scanf("%d%d",&n,&k);
    REP(i,n) scanf("%d",&a[i]);
    sort(a,a+n,greater<int>());
    printf("%d",a[k-1]);
    return 0;
}