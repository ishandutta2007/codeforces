#include<bits/stdc++.h>
#define maxn 1000001
#define mod 998244353
#define int long long
using namespace std;

int qpow(int b,int e){
    if( e == 0 ) return b;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int qp = qpow(b,e/2);
    return ( qp * qp ) % mod;
}

int n, a[maxn], prv, sum[maxn], dp[maxn], ss;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum[i] = ( sum[i-1] + a[i] ) % mod;
    }

    for(int i=1; i<=n; i++){
        prv = ( prv + sum[i] ) % mod;
        dp[i] = prv;
        prv = ( prv + mod - ss ) % mod;
        ss = ( ss * 2 );
        prv = ( prv + ss ) % mod;
        ss = ( ss + sum[i] ) % mod;
        prv = ( prv + dp[i] ) % mod;
    }

    cout << dp[n] << '\n';

    return 0;
}