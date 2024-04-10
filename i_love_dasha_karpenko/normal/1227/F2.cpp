//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

const int N = 2E5+7;
const ll MOD = 998244353;
int A[N];
ll fact[N],rev[N];
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        mult = mult*mult%MOD;
        power = power>>1;
    }
    return x;
}
ll C(int n,int k){
    if (n<k || n<0 || k<0)
        return 0;
    return fact[n]*rev[k]%MOD*rev[n-k]%MOD;
}
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i = 0;i<n;++i){
        cin>>A[i];
    }
    if (k==1){
        cout<<0<<endl;
        return;
    }
    int cnt = n;
    for(int i = 0;i<n;++i){
        if (A[i]==A[(i+1)%n])
            --cnt;
    }
    ll res = binpow(k,n);
    for(int get = 0;get<=cnt;get+=2){
        res = (res-C(cnt,get)*C(get,get/2)%MOD*binpow(k-2,cnt-get)%MOD*binpow(k,n-cnt))%MOD;
        if (res<0)
            res+=MOD;
    }
    res = res*rev[2]%MOD;
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    fact[0] = rev[0] = 1;
    for(int i = 1;i<N;++i){
        fact[i] = fact[i-1]*i%MOD;
        rev[i] = binpow(fact[i],MOD-2);
    }
    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}