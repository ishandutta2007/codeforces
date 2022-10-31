#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 207;
const int SUM = N;
int MOD;
int binpow(ll x,int power){
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
ll fact[N],rev[N];
int C(int n,int k){
    return fact[n]*rev[k]%MOD*rev[n-k]%MOD;
}
int dp[2][SUM][N],mv[N],ms[N];
int last;
int n;

void solve(){

    cin>>n>>MOD;
    fact[0] = 1;
    for(int i = 1;i<N;++i){
        fact[i] = fact[i-1]*i%MOD;
    }
    rev[N-1] = binpow(fact[N-1],MOD-2);
    for(int i = N-2;i>=0;--i){
        rev[i] = rev[i+1]*(i+1)%MOD;
    }

    for(int i = n+1;i>=1;--i){
        int sum = 0,cnt = 0;
        for(int j = i;j<=n+1;++j){
            while(i*j>=sum+j) {
                sum += j, mv[++cnt] = j;
                ms[cnt] = ms[cnt-1]+j;
            }
        }
        if (cnt<n){
            last = i+1;
            break;
        }
    }

    ll res = 0;
    for(int mi = last;mi<=n+1;++mi) {
        memset(dp,0,sizeof(dp));
        for(int add = 1;add<=mi;++add){
            dp[0][0][add] = 1;
        }
        for(int cur = mi+1;cur<=n+1;++cur) {
            for (int w = 0; w <= mi; ++w) {
                for (int cnt = 0; cnt<=cur; ++cnt) {
                    if (!dp[0][w][cnt])
                        continue;
                    int to = (mi*cur-w-cnt*mi)/cur;
                    for (int add = 1;  add<=to; ++add) {
                        if (w+add*(cur-mi)>mi)
                            break;
                        dp[1][w+add*(cur-mi)][cnt+add] = (dp[1][w+add*(cur-mi)][cnt+add]+ll(dp[0][w][cnt]) * C(cnt+add, add))%MOD;
                    }
                }
            }
/*
  200 999999937
 */
            for(int cnt = 0;cnt<=cur;++cnt){
                for (int w = 0; w <= mi; ++w){
                    dp[0][w][cnt]+=dp[1][w][cnt];
                    if (dp[0][w][cnt]>=MOD)
                        dp[0][w][cnt]-=MOD;
                    dp[1][w][cnt] = 0;
                }
            }
        }
        for(int w = 0;w<=mi;++w)
            res+=dp[0][w][n];
        res%=MOD;
    }

    cout<<res%MOD<<endl;
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;


    while(t--)
        solve();

}