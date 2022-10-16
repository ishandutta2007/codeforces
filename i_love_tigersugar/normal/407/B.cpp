#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
using namespace std;
const int mod=(int)1e9+7;
int f[MAX],p[MAX];
int n;
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&p[i]);
    f[1]=0;
    FOR(i,2,n+1) f[i]=(2*f[i-1]%mod-f[p[i-1]]+2+mod)%mod;
    printf("%d",f[n+1]);
}
int main(void) {
    process();
    return 0;
}