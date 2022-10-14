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

int T;
ll N,K;
const ll MOD = 998244353;
const ll MAXN = 200010;
// FASTEXP

ll fexp(ll b, int e){
    ll res = 1;
    for(int i = 0; i<31;i++){
        if(e&(1<<i)){res*=b;res%=MOD;}
        b*=b; b%=MOD;
    }
    return res;
}

// INVERSO MOLTIPLICATIVO

ll inv(ll a){
    return fexp(a,MOD-2);
}

// FATTORIALE / BINOMIALE

ll fact[MAXN];
ll bin (ll a, ll b){
    if(b > a)return 0LL;
    return (((fact[a]*inv(fact[b]))%MOD)*inv(fact[a-b]))%MOD;
}
int main(){
    fact[0] = 1;
    for(ll i = 1; i < MAXN; i++)fact[i] = (fact[i-1]*i)%MOD;
    cin >> N >> K;
    if(K == 0){
        cout << fact[N]; return 0;
    }
    if(K >= N){
        cout << 0; return 0;
    }
    ll res = 2*bin(N,N-K); res%= MOD;
    ll temp = 0;
    for(int i = N-K; i>0; i--){
        if((N-K-i)%2 == 0)temp+=(bin(N-K,i)*fexp(i,N))%MOD;
        else temp+=MOD - (bin(N-K,i)*fexp(i,N))%MOD;
        temp%=MOD;
    }
    cout << (temp*res)%MOD;
    return 0;
}