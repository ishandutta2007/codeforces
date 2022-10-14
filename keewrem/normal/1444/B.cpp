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
ll N;
// INVERSO MOLTIPLICATIVO

const ll MAXN = 360000;
const ll MOD = 998244353;
ll fexp(ll b, ll e){
    ll res = 1;
    for(int i = 0; i<31;i++){
        if(e&(1<<i)){res*=b;res%=MOD;}
        b*=b; b%=MOD;
    }
    return res;
}
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
    vi v(N*2);
    for(auto& x: v)cin >> x;
    sort(v.begin(),v.end());
    ll ans = 0;
    for(int i = 0; i < N; i++)ans+=v[N+i]-v[i];
    ans%=MOD;
    cout << (ans * bin(2*N,N))%MOD;
    return 0;
}