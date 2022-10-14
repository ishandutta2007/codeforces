#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,T,K,a,b,c,d;
ll mod = 998244353;
ll gcd(ll a, ll b){
    if(a == 0)return b;
    return gcd(b%a,a);
}
// FASTEXP

ll fexp(ll b, int e){
    ll res = 1;
    for(int i = 0; i<31;i++){
        if(e&(1<<i)){res*=b;res%=mod;}
        b*=b; b%=mod;
    }
    return res;
}

// INVERSO MOLTIPLICATIVO

ll inv(ll a){
    return fexp(a,mod-2);
}
ll kek[100];
ll fact[100000];
ll bin (ll a, ll b){
    return (((fact[a]*kek[b])%mod)*kek[a-b])%mod;
}

vector<ll> ses,ans; ll res;
int main(){
    fact[0]=1;
    for(ll i = 1; i < 100000; i++)fact[i] = (fact[i-1]*i)%mod;
    cin >> N;
    cin >> T;
    for(int i = 0; i < 100; i++){
        kek[i]=inv(fact[i]);
    }
    if(N%2==0LL)
        ses.push_back(2LL);
    while(N%2LL==0LL){
        N/=2LL;
    }
    for(ll i = 3; i*i <= N; i+=2){
        if(N%i==0LL)
            ses.push_back(i);
        while(N%i==0LL){
            N/=i;
        }
    }
    if(N!=1)ses.push_back(N);
    while(T--){
        scanf("%lld %lld", &a, &b);
        c=gcd(a,b); a/=c; b/= c;
        res = 1;
        ll sos = 0;
        ans.clear();
        for(auto x: ses){
            d = 0;
            while(a%x==0LL){
                d++; a/=x;
            }
            if(d>0){
                sos+=d;
                ans.push_back(d);
            }
        }
        for(auto x: ans){
            res*=bin(sos,x);
            sos-=x;
            res%=mod;
        }
        sos = 0;
        ans.clear();
        for(auto x: ses){
            d = 0;
            while(b%x==0LL){
                d++; b/=x;
            }
            if(d>0){
                sos+=d;
                ans.push_back(d);
            }
        }
        for(auto x: ans){
            res*=bin(sos,x);
            sos-=x;
            res%=mod;
        }
        printf("%lld\n", res);
    }
    return 0;
}