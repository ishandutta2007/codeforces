#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for(int& x : v) cin >> x;
    sort(v.begin(), v.end());
    LL sum = 0;
    for(int i = 0; i < n; i += 1) sum += v[i + n] - v[i];
    vector<LL> g(n + 1);
    for(int i = 1; i <= n; i += 1) g[i] = i == 1 ? 1 : (mod - mod / i) * g[mod % i] % mod;
    sum %= mod;
    for(int i = 1; i <= 2 * n; i += 1) sum = sum * i % mod;
    for(int i = 1; i <= n; i += 1) sum = sum * g[i] % mod;
    for(int i = 1; i <= n; i += 1) sum = sum * g[i] % mod;
    cout << sum;
    return 0;
}