#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
vector<ll> v;

int main(){
    scanf("%lld", &n);
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0) v.push_back(i);
        if(i * i == n) break;
        if(n % i == 0) v.push_back(n / i);
    }
    sort(v.begin(), v.end());
    for(ll i : v) printf("%lld ", i + (n / i) * (i - 1) * i / 2);
}