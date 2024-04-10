#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <ll> vec;

const int MOD = 1000000007;

ll mul(ll a, ll b, int mod){
    a %= mod;
    b %= mod;
    return (a*b)%mod;
}

ll pw(ll a, ll b, int mod){
    if(b == 0) return 1;
    ll res = pw(a, b/2, mod);
    res = mul(res, res, mod);
    if(b%2) res = mul(res, a, mod);
    return res;
}

ll br[200005];
ll p[200005];
ll s[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(!br[x]) vec.push_back(x);
        br[x]++;
    }
    ll res = 1;
    n = vec.size();
    for(int i=0; i<n; i++){
        int c = vec[i];
        if(i == 0) p[i] = br[c]+1;
        else p[i] = mul(p[i-1], br[c]+1, MOD-1);
    }
    for(int i=n-1; i>0; i--){
        int c = vec[i];
        if(i == n-1) s[i] = br[c]+1;
        else s[i] = mul(s[i+1], br[c]+1, MOD-1);
    }
    for(int i=0; i<n; i++){
        int c = vec[i];
        ll p1 = 1;
        if(i > 0) p1 = mul(p1, p[i-1], MOD-1);
        if(i < n-1) p1 = mul(p1, s[i+1], MOD-1);
        for(ll i=1; i<=br[c]; i++){
            res = mul(res, pw(c, mul(i, p1, MOD-1), MOD), MOD);
        }
    }
    cout << res;
    return 0;
}