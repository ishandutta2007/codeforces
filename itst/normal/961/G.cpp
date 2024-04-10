#include<iostream>
#include<cstdio>
//This code is written by Itst
using namespace std;

const int MOD = 1e9 + 7 , MAXN = 2e5 + 3;
int times , K , N , jc[MAXN] , inv[MAXN];

int poww(long long a , int b){
    int times = 1;
    while(b){
        if(b & 1) times = times * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return times;
}

int C(int b , int a){return 1ll * jc[b] * inv[a] % MOD * inv[b - a] % MOD;}

int Stir(int b , int a){
    int ans = 0;
    for(int i = 0 ; i < a ; ++i)
        ans = (ans + MOD + (i & 1 ? -1ll : 1ll) * C(a , i) * poww(a - i , b) % MOD) % MOD;
    return 1ll * ans * inv[a] % MOD;
}

void calc(){
    jc[0] = 1;
    for(int i = 1 ; i <= N ; ++i) jc[i] = 1ll * jc[i - 1] * i % MOD;
    inv[N] = poww(jc[N] , MOD - 2);
    for(int i = N - 1 ; i >= 0 ; --i) inv[i] = inv[i + 1] * (i + 1ll) % MOD;
    times = (Stir(N , K) + (N - 1ll) * Stir(N - 1 , K)) % MOD;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    //freopen("out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin >> N >> K; calc();
    int sum = 0;
    for(int i = 1 ; i <= N ; ++i){
        int a; cin >> a; sum = (sum + a) % MOD;
    }
    cout << 1ll * times * sum % MOD;
    return 0;
}