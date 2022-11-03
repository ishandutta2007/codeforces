#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

ll n,k;
const ll mod = 1000003;

ll max2deg(ll x){
    ll y = x;
    ll ans = 0;
    while(x){
        ans += (x>>1LL);
        x >>= 1LL;
    }
    return ans;
}

ll binpow(ll y,ll x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return y%mod;
    }
    ll ans = binpow((y%mod),x>>1LL)%mod;
    ll ans2 = ans;
    ans *= ans2;
    ans %=mod;
    if(x%2){
        ans *= (y%mod);
        ans %= mod;
    }
    ans %= mod;
    return ans;
}

int main()
{
    cin >> n >> k;
    ll k1 = k-1;
    ll dg = 0;
    while(k1>0){
        k1 >>= 1LL;
        dg++;
    }
    if(dg>n){
        cout << "1 1";
        return 0;
    }
    ll a,b;
    a = 1;
    ll cur = binpow(2,n);
    //500002
    ll deg = max2deg(k-1)+n;
    for(int i=0;i<k;i++){
        a *= cur;
        a %= mod;
        if(cur==0){
            break;
        }
        cur += mod -1;
        cur%=mod;
    }
    a *= binpow(500002,deg);
    b = binpow(2,n);
    b = binpow(b,k);
    b *= binpow(500002,deg);
    a %= mod;
    b %= mod;
    a = b-a+2*mod;
    a%= mod;
    cout << a << " " << b;

    return 0;
}