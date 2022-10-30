#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int N = 5e3+7;
const ll MOD = 998244353;
ll fact[N],rev[N],po[N];
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
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> one;
    for(int i = 1;i<=n;++i){
        char ch; cin>>ch;
        if (ch=='1')
            one.push_back(i);
    }
    if (k==0){
        cout<<"1\n";
        return;
    }
    int sz = one.size();
    ll res = 1;
    for(int i = k-1;i<sz;++i){
        int lb = i-k>=0?one[i-k]+1:1;
        int rb = i+1<sz?one[i+1]-1:n;
        res+=C(rb-lb+1,k)-1;
        if (i-k>=0){
            res-=C(one[i]-lb,k-1)-1;
        }
        res%=MOD;
        res+=MOD*(res<0);
    }
    cout<<res<<endl;

}
signed main(){
    fact[0] = po[0] = 1;
    for(int i = 1;i<N;++i){
        po[i] = (po[i-1]<<1)%MOD;
        fact[i] = fact[i-1]*i%MOD;
    }
    rev[N-1] = binpow(fact[N-1],MOD-2);
    for(int i = N-2;i>=0;--i){
        rev[i] = rev[i+1]*(i+1)%MOD;
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;

    while(t--)
        solve();
}