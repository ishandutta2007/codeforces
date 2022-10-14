#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 200005;
const ll MOD = 998244353;
ll N;
ll fexp(ll b, ll e){
    ll res = 1;
    for(;e;e>>=1){
        if(e&1)res = (res*b)%MOD;
        b = (b*b)%MOD;
    }
    return res;
}

// INVERSO MOLTIPLICATIVO

ll inv(ll a){
    return fexp(a,MOD-2);
}

// FATTORIALE / BINOMIALE

ll fact[MAXN],finv[MAXN];
ll bin (ll a, ll b){
    if(b > a)return 0;
    return (((fact[a]*finv[b])%MOD)*finv[a-b])%MOD;
}

void f_init(){
    fact[0]=1;
    for(ll i = 1; i < MAXN; i++)fact[i] = (fact[i-1]*i)%MOD;
    finv[MAXN-1] = inv(fact[MAXN-1]);
    for(ll i = MAXN-1; i > 0; i--)finv[i-1] = (finv[i]*i)%MOD;
}

int main(){
    f_init();
    cin >> N;
    ll ans = 0;
    for(int i = 0; i <= N; i++){
        if((N-i)%2 == 1)continue;
        else ans+=bin((N-i)/2+i-1,i-1);
    }
    ans%=MOD;
    for(int i = 0; i < N; i++){
        ans = (ans*(MOD/2+1))%MOD;
    }
    cout << ans <<"\n";
    return 0;
}