#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,q,p;
ll fac[1100000],inv[1100000];
ll pw[1100000],Ans[1100000];
ll C(int n,int m){
    if (n<m) return 0;
    return fac[n]*inv[m]%p*inv[n-m]%p;
}
ll Lucas(int n,int m){
    if (n<m) return 0;
    if (!n) return 1;
    return Lucas(n/p,m/p)*C(n%p,m%p)%p;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&a,&q);
    ll mul=a%q; p=1;
    while (mul!=1) mul=1ll*mul*a%q,p++;

    pw[0]=1; for (int i=1;i<p;i++) pw[i]=pw[i-1]*a%q;
    fac[0]=1; for (int i=1;i<p;i++) fac[i]=fac[i-1]*i%p;
    inv[1]=1; for (int i=2;i<p;i++) inv[i]=(p-p/i)*inv[p%i]%p;
    inv[0]=1; for (int i=1;i<p;i++) inv[i]=inv[i-1]*inv[i]%p;
    int sum=0; mul=1;
    for (int i=0;i<n;i++){
        sum=(sum+Lucas(m,i))%p;
        Ans[n-i]=pw[sum];
    }
    for (int i=1;i<=n;i++) printf("%lld ",Ans[i]);
    return 0;
}