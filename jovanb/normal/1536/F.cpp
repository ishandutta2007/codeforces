#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1000000007;

int add(int a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

const int MAXN = 1000000;

int fact[MAXN+5];
int invfact[MAXN+5];

int choose(int n, int k){
    if(n < k || n < 0 || k < 0) return 0;
    int res = fact[n];
    res = mul(res, invfact[k]);
    res = mul(res, invfact[n-k]);
    return res;
}

int izaberi(int n, int k){
    return choose(n-k+1, k);
}

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    fact[0] = 1;
    for(int i=1; i<=n; i++) fact[i] = mul(fact[i-1], i);
    for(int i=0; i<=n; i++) invfact[i] = pw(fact[i], MOD-2);
    int res = 0;
    for(int played=2; played<=n; played+=2){
        int ways = 0;
        int gaps = n - played;
        ways = add(ways, izaberi(n-3, gaps-1));
        ways = add(ways, izaberi(n-1, gaps));
        ways = mul(ways, fact[played]);
        res = add(res, ways);
    }
    cout << mul(2, res) << "\n";
    return 0;
}