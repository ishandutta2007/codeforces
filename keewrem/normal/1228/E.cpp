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

const ll MOD = 1000000007,MAXN = 600;

ll fexp(ll b, ll e){
    ll res = 1;
    for(int i = 0; i<31;i++){
        if(e&(1LL<<i)){res*=b;res%=MOD;}
        b*=b; b%=MOD;
    }
    return res;
}
ll inv(ll a){
    return fexp(a,MOD-2);
}

// FATTORIALE / BINOMIALE

ll fact[MAXN];
ll bin (ll a, ll b){
    return (((fact[a]*inv(fact[b]))%MOD)*inv(fact[a-b]))%MOD;
}

ll N,K,a,rer = 0;

int main(){
    fact[0]=1;
    for(ll i = 1; i < MAXN; i++)fact[i] = (fact[i-1]*i)%MOD;
    cin >> N >> K;
    if(K == 1){cout << 1; return 0;}
    for(ll i = 0; i <= 2*N; i++){
        a = 0;
        for(ll j = max(0LL,i-N); j <= i && j <= N; j++){
            a+=((bin(N,i-j)*bin(N,j))%MOD)*((fexp(K-1,(N*i)-j*(i-j))*fexp(K,(N*N)-((N*i)-j*(i-j))))%MOD);
            //cout << (N*N)-((N*i)-j*(i-j)) << " i "<<i << " j "<< j<< "\n";
            a %= MOD;
        }

    //    cout << "a" << a <<"\n";
        if(i&1LL)rer+=MOD-a; else rer+=a;
        rer%=MOD;
    }
    cout << rer;
    return 0;
}