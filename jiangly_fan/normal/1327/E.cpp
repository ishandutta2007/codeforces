#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 200000;
LL p[maxn + 1];
LL f(int n){
    return n == 1 ? 10 : p[n - 2] * (81 * (n - 2) + 180) % mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i <= n; i += 1) p[i] = i ? p[i - 1] * 10 % mod : 1;
    for(int i = n; i; i -= 1) cout << f(i) << " ";
    return 0;
}