#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod=(int)1e9+7;
int f[MAX],s[MAX];
int n,len;
void precount(void) {
    scanf("%d%d",&n,&len);
    f[0]=1;
    FOR(i,1,MAX-1) {
        f[i]=f[i-1];
        if (i>=len) f[i]=(f[i]+f[i-len])%mod;
        s[i]=(s[i-1]+f[i])%mod;
    }
}
void process(void) {
    REP(zz,n) {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",(s[r]-s[l-1]+mod)%mod);
    }
}
int main(void) {
    precount();
    process();
    return 0;
}