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
const ll MOD = 998244353;
const ll MAXN = 500010;

ll fexp(ll b, int e){
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
ll fact[MAXN];
ll bin (ll a, ll b){
    if(b > a)return 0;
    return (((fact[a]*inv(fact[b]))%MOD)*inv(fact[a-b]))%MOD;
}

int T;
ll N,K;

int main(){
    fact[0]=1;
    for(ll i = 1; i < MAXN; i++)fact[i] = (fact[i-1]*i)%MOD;
    cin >> N >> K;
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        ans += bin(N/i-1,K-1);
        ans%=MOD;
    }
    cout << ans;
    return 0;
}