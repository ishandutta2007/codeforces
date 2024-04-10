#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
vi primes;
const int N = 1e6;
int factor[N], mu[N];
void pre(){
    for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    for(int i = 2;i<N;i++) if(!factor[i]) primes.pb(i), factor[i] = i;
    mu[1] = 1;
    for(int i = 2;i < N; i++){
        int p = factor[i], x = i/p;
        mu[i] = (x % p == 0) ? 0 : -mu[x];
    }   
}
#define ll long long
const ll mod = 1e9 + 7;
int pw2[N], cntd[N], cnt[N];
int main(){
    pre();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        cnt[x] ++;
    }
    pw2[0] = 1;
    for(int i = 1; i < N; i++){
        pw2[i] = (pw2[i - 1] * 1ll * 2) % mod;
        for(int j = i; j < N; j+= i) cntd[i] += cnt[j];
    }
    ll ans = 0;
    for(int i = 1; i < N; i++) ans += mu[i] * (pw2[cntd[i]] - 1);
    ans %= mod;
    if(ans < 0)    ans += mod;
    printf("%lld\n", ans);
}