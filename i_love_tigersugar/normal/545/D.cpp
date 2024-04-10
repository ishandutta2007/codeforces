#include<bits/stdc++.h>
#define MAX   100100
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int a[MAX],n;
void process(void) {
    scanf("%d",&n);
    REP(i,n) scanf("%d",&a[i]);
    sort(a,a+n);
    long long sum=0;
    int cnt=0;
    REP(i,n) if (sum<=a[i]) {
        cnt++;
        sum+=a[i];
    }
    printf("%d\n",cnt);
}
int main(void) {
    process();
    return 0;
}