#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;
const int MOD = 1000000007;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }
int sub(int a, int b){ return add(a, MOD - b); }

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int res;

int fact[N+5], invfact[N+5];

int choose(int n, int k){
    if(n < k || n < 0 || k < 0) return 0;
    int res = fact[n];
    res = mul(res, invfact[k]);
    res = mul(res, invfact[n - k]);
    return res;
}

int n, k;

vector <int> graf[N+5];

int dfs(int v, int p){
    int sz = 1;
    vector <int> vec;
    int od = 0;
    for(auto c : graf[v]){
        if(c == p) continue;
        int x = dfs(c, v);
        vec.push_back(x);
        sz += x;
        od = sub(od, choose(x, k));
    }
    vec.push_back(n - sz);
    od = sub(od, choose(n - sz, k));
    for(auto c : vec){
        od = add(od, choose(c, k));
        int tot = choose(n - c, k);
        res = add(res, mul(n - c, mul(c, add(tot, od))));
        od = sub(od, choose(c, k));
    }
    int tot = choose(n, k);
    res = add(res, mul(n, add(tot, od)));
    return sz;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> n >> k;
    fact[0] = 1;
    for(int i=1; i<=n; i++) fact[i] = mul(i, fact[i - 1]);
    invfact[n] = pw(fact[n], MOD - 2);
    for(int i=n-1; i>=0; i--) invfact[i] = mul(invfact[i+1], i + 1);
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0);
    cout << res << "\n";
    return 0;
}