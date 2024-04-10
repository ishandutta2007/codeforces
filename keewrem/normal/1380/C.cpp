#include<bits/stdc++.h>
#define pb push_back
#define MAXN 200010
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vll;
const ll MOD = 1000000007;

ll sum(ll a, ll b){
    while(a+b>MOD)a-=MOD;
    return a+b;
}

ll mult(ll a, ll b){
    return (a*b)%MOD;
}

ll fexp(ll base, ll exp){
    ll r = 1;
    for(ll i = 1; i <= exp; i<<=1){
        if(i&exp)r=mult(r,base);
        base=mult(base,base);
    }
    return r;
}

ll inv(ll a){
    return fexp(a,MOD-2);
}

ll fact[MAXN]; ll finv[MAXN];
void f_init(){
    fact[0]=1;
    for(ll i = 1; i < MAXN; i++){
        fact[i]=mult(fact[i-1],i);
    }
    finv[MAXN-1]=inv(fact[MAXN-1]);
    for(ll i = MAXN-1; i; i--){
        finv[i] = mult(finv[i+1],i);
    }
}

ll bin(ll a, ll b){
    if(b > a)return 0;
    return mult(fact[a], mult(finv[b],finv[a-b]));
}

ll N,T,M,K,a,b,c;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        vll v(N);
        for(auto &x: v)cin >> x;
        sort(v.rbegin(),v.rend());
        int lf = 0;
        int res= 0;
        for(int i = 0; i < N; i++){
            lf ++;
            if(v[i]*lf>=K){
                lf = 0; res++;
            }
        }
        cout << res <<"\n";
    }
    return 0;
}