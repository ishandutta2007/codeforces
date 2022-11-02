#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
typedef long long LL;
const int maxn=1e6+5;
ll a[maxn],b[maxn];
int n;
ll ans;
const LL m=7, aa[m]={2, 3, 5, 7, 11, 13, 17};
LL mul(LL u, LL v, LL p) {
    return (u * v - LL((long double) u * v / p) * p + p) % p;
}
LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = mul(x, x, MOD))
        if (n & 1) ret = mul(ret, x, MOD);
    return ret;
}
bool checkQ(LL a, LL n) {
    if (n == 2 || a >= n) return 1;
    if (n == 1 || !(n & 1)) return 0;
    LL d = n - 1;
    while (!(d & 1)) d >>= 1;
    LL t = bin(a, d, n);  // 
    while (d != n - 1 && t != 1 && t != n - 1) {
        t = mul(t, t, n);
        d <<= 1;
    }
    return t == n - 1 || d & 1;
}

bool primeQ(LL n) {
    static vector<LL> t = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    if (n <= 1) return false;
    for (LL k: t) if (!checkQ(k, n)) return false;
    return true;
}
ll gcd(ll a,ll b){
    while (b){
        a%=b; swap(a,b);
    }
    return a;
}
LL pollard_rho(LL n, LL c) {
    LL x = rand()%(n-1)+1, y = x;
    auto f = [&](LL v) { LL t = mul(v, v, n) + c; return t < n ? t : t - n; };
    while (1) {
        x = f(x); y = f(f(y));
        if (x == y) return n;
        LL d = gcd(abs(x - y), n);
        if (d != 1) return d;
    }
}

LL fac[100], fcnt; // 
void get_fac(LL n, LL cc = 19260817) {
    if (n == 4) { fac[fcnt++] = 2; fac[fcnt++] = 2; return; }
    if (primeQ(n)) { fac[fcnt++] = n; return; }
    LL p = n;
    while (p == n) p = pollard_rho(n, --cc);
    get_fac(p); get_fac(n / p);
}
inline ll read(){
    ll ans=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') ch=getchar();
    while (ch>='0'&&ch<='9'){
        ans=ans*10+ch-'0'; ch=getchar();
    }
    return ans;
}
ll solve(ll mod){
    ll sol=0;
    int i;
    for (i=0;i<n;i++) b[i]=a[i]%mod;
    for (i=0;i<n;i++){
        sol+=min(b[i],mod-b[i]);
        if (sol>ans) break;
        b[i+1]=(b[i+1]+b[i])%mod;
    }
    return sol;
}
int main(){
    int i;
    ll tot;
    n=read(); tot=0;
    for (i=0;i<n;i++) tot+=(a[i]=read());
    if (tot==1){
        puts("-1"); return 0;
    }
    ans=1e18;
    get_fac(tot);
    sort(fac,fac+fcnt); fcnt=unique(fac,fac+fcnt)-fac;
    for (i=0;i<fcnt;i++) ans=min(ans,solve(fac[i]));
    printf("%lld\n",ans);
    return 0;
}