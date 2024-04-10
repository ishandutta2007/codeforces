#include<bits/stdc++.h>
#define MAX   111
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int m,n;
int a[MAX],b[MAX];
int main(void) {
    scanf("%d",&m);
    REP(i,m) scanf("%d",&a[i]);
    scanf("%d",&n);
    REP(i,n) scanf("%d",&b[i]);
    sort(a,a+m);
    sort(b,b+n);
    int j=0;
    int res=0;
    REP(i,m) {
        while (j<n && b[j]<a[i]-1) j++;
        if (j<n && a[i]-1<=b[j] && b[j]<=a[i]+1) {
            res++;j++;
        }
    }
    printf("%d",res);
    return 0;
}