#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

unordered_map <int, int> u;
ll br[2005];
int cnt;
ll dp[2005][2005];


ll add(ll a, ll b){
    return (a+b)%MOD;
}

ll mul(ll a, ll b){
    return (a*b)%MOD;
}

ll pw(ll a, ll b){
    if(b == 0) return 1;
    ll res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

ll fact[100005];

ll inv(ll a){
    return pw(a, MOD-2);
}

ll bin(ll a, ll b){
    if(a < b) return 0;
    if(b < 0) return 0;
    ll res = fact[a];
    ll d1 = fact[a-b];
    d1 = inv(d1);
    ll d2 = fact[b];
    d2 = inv(d2);
    res = mul(res, d1);
    res = mul(res, d2);
    return res;
}

ll niz[100005];

bool good(int x){
    while(x){
        if(x%10-4 && x%10-7) return 0;
        x /= 10;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    fact[0] = 1;
    for(int i=1; i<=100000; i++){
        fact[i] = mul(fact[i-1], i);
    }
    int n, k;
    cin >> n >> k;
    int d = n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        if(good(niz[i])){
            d--;
            if(!u[niz[i]]){
                u[niz[i]] = ++cnt;
            }
            br[u[niz[i]]]++;
        }
    }
    dp[0][0] = 1;
    for(int i=0; i<cnt; i++){
        for(int j=0; j<=i; j++){
            dp[i+1][j] = add(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1] = add(dp[i+1][j+1], mul(dp[i][j], br[i+1]));
        }
    }
    ll res = 0;
    for(int j=0; j<=cnt; j++){
        //cout << dp[cnt][j] << " " << bin(d, k-j) << endl;
        res = add(res, mul(dp[cnt][j], bin(d, k-j)));
    }
    cout << res;
    return 0;
}