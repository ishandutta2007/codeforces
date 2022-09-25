#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
constexpr LL mod = 998244353;
int p[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i += 1) cin >> p[i];
    cout << (LL)(n - k + 1 + n) * k / 2 << " ";
    LL ans = 1;
    vector<int> v;
    for(int i = 1; i <= n; i += 1) if(p[i] > n - k) v.push_back(i);
    for(int i = 0; i + 1 < (int)v.size(); i += 1) ans = ans * (v[i + 1] - v[i]) % mod;
    cout << ans;
    return 0;
}