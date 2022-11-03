#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    vector<ll> v;
    ll a;
    ll n, l;
    cin >> n >> l;
    for(ll i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    ll ans = 2 * max(v[0], l - v[v.size() - 1]);
    for(ll i = 0; i + 1 < v.size(); i++){
        ans = max(ans, v[i + 1] - v[i]);
    }
    cout << fixed << setprecision(15) << ans * 0.5 << endl;
    return 0;
}