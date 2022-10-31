#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MOD = 1e9+7;
const int N = 3e6+7;
ll binpow(ll x,int power){
    ll mult = x%MOD;
    x = 1;
    while(power){
        if (power&1)
            x = x*mult%MOD;
        power = power>>1;
        mult = mult*mult%MOD;
    }
    return x;
}
ll rev[N],fact[N];
ll C(int n,int k){
    if (n<0 || k<0 || n<k)
        return 0;
    return fact[n]*rev[k]%MOD*rev[n-k]%MOD;
}
void norm(ll &x){
    if (abs(x)>=MOD*2){
        x%=MOD;
        if (x<0)
            x+=MOD;
    }
    else{
        if (x<0)
            x+=MOD;
        if (x>=MOD)
            x-=MOD;
    }
}
ll up(ll x,ll div){
    return x/div+(x%div!=0);
}
ll down(ll x,ll div){
    return x/div;
}
ll S[N],dp[3][N];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout<<up(4,3)*3-2<<endl;
    fact[0] = rev[0] = 1;
    for(int i = 1;i<N;++i){
        fact[i] = fact[i-1]*i%MOD;
    }
    rev[N-1] = binpow(fact[N-1],MOD-2);
    for(int i = N-2;i>=0;--i){
        rev[i] = (rev[i+1]*(i+1))%MOD;

    }
    ll n,q;
    cin>>n>>q;
    n*=3;

    S[0] = n;
    for(int k = 1;k<=n;++k){
        S[k] = C(n+1,k+1);
        //norm(S[k]);
        //cout<<S[k]<<' ';
    }
    dp[0][0] = up(n,3);
    dp[1][0] = up(n-1,3);
    dp[2][0] = up(n-2,3);
    ll rval = binpow(3,MOD-2);
    for(int k = 1;k<=n;++k){
        // dp[0][k] = (dp[1][k]+luft1)-(dp[0][k]+luft2)
        ll delta1 = 0;
        {
            ll luft1 = 0;
            if (down(n,3)*3+1>n)
                luft1 += C(down(n,3)*3+1,k);
            if (up(k,3)*3-2>=k)
                luft1 -= C(up(k,3)*3-2,k);
            norm(luft1);
            ll luft2 = 0;
            if (up(k,3)*3-3>=max(1,k-1))
                luft2-=C(up(k,3)*3-3,k-1);
            delta1 = dp[0][k-1]+luft2-luft1;
            delta1 = -delta1;
            norm(delta1);

        }
        // dp[1][k] = (dp[2][k]+luft1)-(dp[1][k-1]+luft2)
        ll delta2 = 0;
        {
            ll luft1 = 0;
            if (down(n-1,3)*3+1+1>n)
                luft1 += C(down(n-1,3)*3+2,k);
            if (up(k-1,3)*3+1-2>=k)
                luft1 -= C(up(k-1,3)*3-2+1,k);
            ll luft2 = 0;
            if (up(k-1,3)*3+1-3>=k-1)
                luft2-=C(up(k-1,3)*3+1-3,k-1);
            delta2 = luft1-luft2-dp[1][k-1];
            delta2 = -delta2;
            norm(delta2);
        }
        ll x3 = S[k]-delta1-delta2;
        norm(x3);
        dp[1][k] = (x3*rval)%MOD;
        dp[0][k] = dp[1][k]+delta1;
        dp[2][k] = dp[1][k]+delta2;
        norm(dp[0][k]);
        norm(dp[2][k]);
    }
    while(q--){
        int x;
        cin>>x;
        cout<<dp[0][x]<<endl;
    }
    return 0;
}