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

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int a[200005];
map <int, int> cnt;
int fact[200005];

int choose(int n, int k){
    int res = fact[n];
    res = mul(res, pw(fact[k], MOD-2));
    res = mul(res, pw(fact[n-k], MOD-2));
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    fact[0] = 1;
    for(int i=1; i<=2*n; i++) fact[i] = mul(fact[i-1], i);
    ll x = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        x += a[i];
    }
    if(x%n){
        cout << "0\n";
        return 0;
    }
    x /= n;
    int larger = 0;
    int smaller = 0;
    int deli = 1;
    for(int i=1; i<=n; i++){
        cnt[a[i]]++;
        if(a[i] > x) larger++;
        else if(a[i] < x) smaller++;
    }
    for(auto c : cnt){
        deli = mul(deli, fact[c.second]);
    }
    deli = pw(deli, MOD-2);
    if(larger == 0){
        cout << "1\n";
        return 0;
    }
    if(larger == 1 || smaller == 1){
        int res = mul(fact[n], deli);
        cout << res << "\n";
        return 0;
    }
    int res = choose(n, smaller+larger);
    res = mul(res, fact[n-smaller-larger]);
    res = mul(res, 2);
    res = mul(res, fact[smaller]);
    res = mul(res, fact[larger]);
    res = mul(res, deli);
    cout << res << "\n";
    return 0;
}