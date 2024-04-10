#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
int a[MAX+10];
ll f[MAX+10];
int n;
void process(void) {
    scanf("%d",&n);
    REP(zz,n) {
        int t;
        scanf("%d",&t);
        a[t]++;
    }
    f[1]=a[1];
    FOR(i,2,MAX) {
        if (a[i]==0) f[i]=f[i-1];
        else f[i]=max(f[i-1],f[i-2]+1LL*a[i]*i);
    }
    cout<<f[MAX];
}
int main(void) {
    process();
    return 0;
}