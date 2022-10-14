#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) int((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 998244353;
// INVERSO MOLTIPLICATIVO
const int MAXN = 5000;
ll fexp(ll b, ll e){
    ll res = 1;
    for(;e;e>>=1){
        if(e&1)res = (res*b)%MOD;
        b = (b*b)%MOD;
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


void solve(){
    ll M,N; cin >> N >> M;
    ll ans = 0;
    for(int i = 1; i < N; i++){
        ll p = 0;
        for(int j = 1; j < M; j++){
            p += bin(N-i+j-1,N-i) * bin(N-i-1+M-j,M-j);
            p%=MOD;
            ans += p*((bin(M-j-1+i,i) * bin(j+i-1,j))%MOD);
            ans %= MOD;
        }
    }
    swap(M,N);
    for(int i = 1; i < N; i++){
        ll p = 0;
        for(int j = 1; j < M; j++){
            ans += p*((bin(M-j-1+i,i) * bin(j+i-1,j))%MOD);
            ans %= MOD;
            p += bin(N-i+j-1,N-i) * bin(N-i-1+M-j,M-j);
            p%=MOD;
        }
    }
    //ans += bin(M+N-1,N);
    //ans += bin(M+N-1,M);
    cout << (ans*2)%MOD << endl;
    return;
}

int main(){
    f_init();
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}