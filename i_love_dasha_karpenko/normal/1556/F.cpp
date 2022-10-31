#pragma GCC Optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int MOD = 1e9+7;
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
const int MAXN = 2e6+7;
ll rev[MAXN];
const int N = 15;
int A[N],po[N],vis[N];
const int masksz = 1<<N;
ll dp[masksz],calc[N][masksz];
ll P(vector<int> &a,int mask){
    
    ll ret = 1;
    for(int v:a){
        ll r = calc[v][mask];
        ret = ret*r%MOD;

    }
    return ret;
}
void solve(){
    int n;
    cin>>n;
    for(int i = 0;i<n;++i){
        cin>>A[i];
    }

    int sz = 1<<n;
    for(int i = 0;i<n;++i){
        for(int mask = 1;mask<sz;++mask){
            calc[i][mask] = 1;
            for(int bit = 0;bit<n;++bit){
                if (po[bit]&mask)
                    calc[i][mask] = A[i]*rev[A[i]+A[bit]]%MOD*calc[i][mask]%MOD;
            }
        }
        calc[i][0] = 1;
    }
    ll res = 0;
    for(int mask = 1;mask<sz;++mask){
        vector<int> win;
        for(int bit = 0;bit<n;++bit){
            if (po[bit]&mask)
                win.push_back(bit),vis[bit] = 1;
        }
        ll pwin = P(win,(sz-1)^mask);
        ll pcyc = 1;
        for(int sub = (mask-1)&mask;sub>0;sub = (sub-1)&mask){
            vector<int> act;
            for(int bit = 0;bit<n;++bit){
                if (!(po[bit]&mask))
                    continue;
                if (po[bit]&sub)
                    act.push_back(bit);

            }
            pcyc = (pcyc-dp[sub]*P(act,mask^sub)+MOD)%MOD;
        }
        dp[mask] = pcyc;
        res = (pcyc*pwin%MOD*ll(win.size())%MOD+res)%MOD;
    }
    cout<<res<<endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = 1;
    for(int i = 1;i<N;++i)
        po[i] = po[i-1]*2;
    for(int i = 1;i<MAXN;++i){
        rev[i] = binpow(i,MOD-2);
    }
    int t;
    //cin>>t;
    t = 1;
    while(t--)
        solve();
    return 0;
}