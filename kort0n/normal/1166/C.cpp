#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] = abs(v[i]);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(int i = 0; i < v.size(); i++) {
        auto itr = upper_bound(v.begin(), v.end(), 2 * v[i]);
        ans += distance(v.begin(), itr) - i - 1;
    }
    cout << ans << endl;
    return 0;
}