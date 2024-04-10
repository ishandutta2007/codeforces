#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int MOD;

int add(int a, int b){
    return (a+b)%MOD;
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int fact[250005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n >> MOD;
    int res = 0;
    fact[0] = 1;
    for(int i=1; i<=n; i++) fact[i] = mul(i, fact[i-1]);
    for(int len=1; len<=n; len++){
        res = add(res, mul(mul(mul(n-len+1, fact[len]), n-len+1), fact[n-len]));
    }
    cout << res;
    return 0;
}