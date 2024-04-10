#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mod;

inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

int main(){
    int a, b, p;
    ll x;
    cin >> a >> b >> p;
    cin >> x;
    mod = p;
    int an = 1;
    int inva = inv(a);
    ll ans = 0;
    for(int r = 0; r < p - 1; r++){
        int c = mul(b, an);
        an = mul(an, inva);
        int t = sub(r, c);
        ll mx = x - r;
        if(mx < 0) continue;
        mx /= (p - 1);
        if(mx < t) continue;
        ans += 1 + (mx - t) / p;
    }
    cout << ans;
}