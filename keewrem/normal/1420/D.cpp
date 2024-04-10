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
const int MAXN = 300010; const ll MOD = 998244353;
int T;
ll N,K;
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
ll fact[MAXN],finv[MAXN];
ll bin (ll a, ll b){
    if(a < b)return 0;
    return (((fact[a]*finv[b])%MOD)*finv[a-b])%MOD;
}

void f_init(){
    fact[0]=1;
    for(ll i = 1; i < MAXN; i++)fact[i] = (fact[i-1]*i)%MOD;
    finv[MAXN-1] = inv(fact[MAXN-1]);
    for(ll i = MAXN-1; i > 0; i--)finv[i-1] = (finv[i]*i)%MOD;
}

int a,b;
int main(){
    f_init();
    cin >> N >> K;
    vector<pair<int,int>> v;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        v.pb({a,-1});
        v.pb({b,1});
    }
    ll c = 0;
    ll ans = 0;
    sort(v.begin(),v.end());
    for(auto x: v){
        c-=x.se;
    //    cout << "c "<<c <<endl;
        if(x.se < 0)ans+=bin(c-1,K-1);
        ans%=MOD;
    }
    cout << ans << "\n";
    return 0;
}