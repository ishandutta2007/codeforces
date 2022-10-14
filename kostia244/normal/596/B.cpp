#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 505;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    ll ans = abs(a[0]);
    for(int i = 1; i < n; i++) ans += abs(a[i]-a[i-1]);
    cout << ans << '\n';
}