#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define po(x) (1ll<<x)
const int N = 1e3+7;
const int MAXN = 1e5;
const ll MOD = 998244353;
int A[N];
ll dp[N][N],cnt[N];
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
    if (n<0 || k<0 || n<k)
        return 0;
    return fact[n]*rev[k]%MOD*rev[n-k]%MOD;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    for(int i = 1;i<N;++i){
        fact[i] = fact[i-1]*i%MOD;
    }
    rev[N-1] = binpow(fact[N-1],MOD-2);
    for(int i = N-2;i>=0;--i){
        rev[i] = rev[i+1]*(i+1)%MOD;
    }
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    sort(A+1,A+1+n);
    ll res = 0,prev = 0;
    for(int mx = MAXN/(k-1);mx>=0;--mx){
        int ptr = 0;
        ll sum = 0;
        for(int i = 0;i<=n;++i)
            cnt[i] = 0;
        cnt[0] = 1;
        for(int i = 1;i<=n;++i){
            while(ptr+1<i && A[i]-A[ptr+1]>=mx) {
                ++ptr;
                for (int j = 0; j <= k; ++j)
                    cnt[j] = (cnt[j] + dp[ptr][j]) % MOD;
            }
            for(int j = 1;j<=k;++j){
                dp[i][j] = cnt[j-1];
            }
        }
        while(ptr<n){
            ++ptr;
            for (int j = 0; j <= k; ++j)
                cnt[j] = (cnt[j] + dp[ptr][j]) % MOD;
        }
        for(int i = k;i<=n;++i){
            sum = (sum+C(i-1,k-1)*cnt[i])%MOD;
        }
        res = (res+(sum+MOD-prev)*mx)%MOD;
        prev = sum;
    }
    cout<<res<<endl;
    return 0;
}