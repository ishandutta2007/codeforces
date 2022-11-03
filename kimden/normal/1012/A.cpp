#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for(int i = 0; i < 2 * n; ++i){
        cin >> a[i];
    }
    sort(all(a));
    ll x = a[n - 1] - a[0];
    ll y = a[2 * n - 1] - a[n];
    ll ans = x * y;
    for(int i = 1; i + n - 1 < 2 * n - 1; ++i){
        ans = min(ans, ll(a[2 * n - 1] - a[0]) * ll(a[i + n - 1] - a[i]));
    }
    cout << ans << endl;

    return 0;
}