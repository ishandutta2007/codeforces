#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e6+5;
typedef long long ll;
typedef long long LL;
LL Prime[4] = {2, 13, 23, 1662803 } ;

inline LL expow(LL a, LL b, LL p){
    LL res = 1 ;
    while (b){
        if (b & 1) 
            (res *= a) %= p ;
        (a *= a) %= p, b >>= 1 ; 
    }
    return res % p ;
}
inline bool Test(LL p, LL x){
    LL r = 0, d = x - 1 ;
    while (!(d & 1)) d >>= 1, ++ r ;
    for (LL i = expow(p, d, x), j ; r ; -- r){
        j = i * i % x ;
        if (j == 1){
            if (i == 1 || i == x - 1) 
                return 1 ; 
            return 0 ;
        }
        i = j ;
    }
    return 0 ;
}
inline bool Miller_Rabin(LL x){
    if (x == 1) return 0 ;
    for (int i = 0 ; i < 4 ; ++ i){
        if (x == Prime[i]) return 1 ;
        if (!(x % Prime[i])) return 0 ;
        if (!Test(Prime[i], x)) return 0 ;
    }
    return 1 ;
}
LL res[maxn], tot ;
inline int pksrand(){
    return rand() << 15 ^ rand() ;
} // 2
inline LL Irand(LL x){
    return (((LL)pksrand()) << 30 ^ pksrand()) % x ; //2
}
inline LL guisuMul(LL a, LL b, LL x){
    return (a * b - (LL) ((long double) a * b / x + 1e-9) * x) % x;
} 
inline LL qwq(LL x){
    LL A = Irand(x), C = Irand(x) ;
    LL t1 = A, t2 = (guisuMul(A, A, x) + C) % x ; // 1
    LL dif = max(t1, t2) - min(t1, t2), G = __gcd(x, dif) ;
    while (G == 1){
        t1 = (guisuMul(t1, t1, x) + C) % x ;
        t2 = (guisuMul(t2, t2, x) + C) % x ;
        t2 = (guisuMul(t2, t2, x) + C) % x ;
        dif = max(t1, t2) - min(t1, t2), G = __gcd(x, dif) ;
    }
    return G ;
}
inline void Pollard_Rho(LL x){
    if (x == 1) return ;
    if (Miller_Rabin(x)) {
        res[tot++] = x ; return ;
    }
    LL y = x ; while (y == x) y = qwq(x) ;
    Pollard_Rho(y), Pollard_Rho(x / y) ;
}
int aa[maxn];
int n;
ll all;
ll ans=1e18;
ll bb[maxn];
ll solve(ll mod){
    ll ans=0;
    int i;
    for (i=0;i<n;i++) bb[i]=aa[i]%mod;
    for (i=0;i<n;i++){
        ans+=min(bb[i],mod-bb[i]);
        bb[i+1]=(bb[i+1]+bb[i])%mod;
    }
    return ans;
}
int main(){
    int i;
    scanf("%d",&n);
    all=0;
    for (i=0;i<n;i++){
        scanf("%d",&aa[i]);
        all+=aa[i];
    }
    if (all==1){
        puts("-1"); return 0;
    }
    Pollard_Rho(all);
    sort(res,res+tot); tot=unique(res,res+tot)-res;
    for (i=0;i<tot;i++) ans=min(ans,solve(res[i]));
    printf("%lld\n",ans);
    return 0;
}