#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

const int MAXN = 500000;

int fact[MAXN+5];
int invfact[MAXN+5];

int choose(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    int res = fact[n];
    res = mul(res, invfact[n-k]);
    res = mul(res, invfact[k]);
    return res;
}

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    int lim = r-n;
    lim = min(lim, 1-l);
    int res = mul(lim, choose(n, n/2));
    if(n%2) res = add(res, mul(lim, choose(n, n/2+1)));
    int mora0 = 0, mora1 = n+1;
    int x = lim;
    for(;;){
        x++;
        if((mora0+1)-x < l) mora0++;
        if((mora1-1)+x > r) mora1--;
        if(mora0 >= mora1) break;
        int g = choose(n-mora0-(n-mora1+1), n/2 - mora0);
        if(n%2) g = add(g, choose(n-mora0-(n-mora1+1), n/2 - mora0 + 1));
        res = add(res, g);
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    fact[0] = invfact[0] = 1;
    for(int i=1; i<=MAXN; i++) fact[i] = mul(fact[i-1], i);
    invfact[MAXN] = pw(fact[MAXN], MOD-2);
    for(int i=MAXN-1; i>=1; i--) invfact[i] = mul(invfact[i+1], i+1);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}