#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int mod =  998244353;

int main() {
    int a, b, c, i, j, y, x, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    long long fct = n, ts = 0;
    for (long long l = 1; l <= n; ++l)
        fct = (fct * l) % mod;
    for (long long l = 2; l <= n; ++l)
        ts = (ts * l + l) % mod;
    cout << (fct - ts + mod) % mod;
}