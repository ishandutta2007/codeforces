#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int K = 720720+7;
const ll MOD = 998244353;
ll cnt[2][K];
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
void solve() {
    int n,start,x,y,k,M;
    cin>>n>>start>>x>>y>>k>>M;



    int lim = 1;
    for(int i = 2;i<k;++i)
        lim = lim/__gcd(i,lim)*i;

    ll cur = start;

    ll res = 0;
    ll rvl = binpow(n,MOD-2);
    ll base = binpow(n,k);
    ll MU = base*rvl%MOD*k%MOD;
    for(int i = 0;i<n;++i){
        res+=MU*(cur-cur%lim)%MOD;
        res-=MOD*(res>=MOD);
        cnt[0][cur%lim]+=base;
        cnt[0][cur%lim]-=MOD*(cnt[0][cur%lim]>=MOD);
        cur = (cur*x+y)%M;
    }

    for(int st = 1;st<=k;++st){
        for(int v = 0;v<lim;++v){
            if (!cnt[0][v])
                continue;
            int rv = v;
            int nv = rv-rv%st;
            res += cnt[0][v] * rv % MOD * rvl % MOD;
            res -= MOD * (res >= MOD);
            if (st!=k) {
                cnt[1][nv] += cnt[0][v] * rvl % MOD;
                cnt[1][nv] -= MOD * (cnt[1][nv] >= MOD);
            }
        }

        for(int v = 0;v<lim;++v){
            cnt[0][v] = cnt[0][v]*(n-1)%MOD*rvl%MOD;
            cnt[0][v]+=cnt[1][v];
            cnt[0][v]-=MOD*(cnt[0][v]>=MOD);
            cnt[1][v] = 0;
        }

    }
    for(int i = 0;i<=lim;++i)
        cnt[0][i] = cnt[1][i] = 0;
    cur = (cur*x+y)%M;

    int val = binpow(n,MOD-2);
    //cout<<binpow(val,k)*382842030%MOD<<endl;
    cout<<res<<endl;//*binpow(val,k)%MOD<<endl;
}

signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}