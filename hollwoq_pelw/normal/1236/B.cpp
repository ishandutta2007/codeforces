#include <bits/stdc++.h>
using namespace std;
// fomula (2^m-1)^n%mod
const long mod = 1e9+7;
long long pow_mod(long long b, long long p){
    if (p == 0) return 1;
    if (p == 1) return b;
    long long x = pow_mod(b, p/2);
    return (x*x%mod)*pow_mod(b, p%2)%mod;
}

int main(){
    long long m,n;
    cin >> n >> m;
    cout << pow_mod(pow_mod(2,m)-1, n) << endl;
}