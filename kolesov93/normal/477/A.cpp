#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll div2 = (MOD + 1) / 2;

ll sum(ll a, ll b) {
    ll x = (b - a + 1);
    if (x >= MOD) x %= MOD;
    ll y = (a + b);
    if (y >= MOD) y %= MOD;
    x = (x * y) % MOD;
    return (x * div2) % MOD;
}

int main() {
    ll a, b;
    cin >> a >> b;

    ll modsum = sum(1, b - 1);
    ll ans = (modsum * a) % MOD;
    ll asum = sum(1, a);

    ll nxt = (asum * b) % MOD;
    nxt = (nxt * modsum) % MOD;

    cout << (ans + nxt) % MOD << endl;

    return 0;
}