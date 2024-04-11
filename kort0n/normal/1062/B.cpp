#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret;
    if(b & 1) ret *= a;
    return ret;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll ans2 = 1;
    vector<l_l> v;
    for(ll i = 2; i * i <= n; i++) {
        ll num = 0;
        while(n % i == 0) {
            n /= i;
            num++;
        }
        if(num == 0) continue;
        v.push_back({i, num});
    }
    if(n > 1) {
        v.push_back({n, 1});
    }
    ll maxi = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].second != v[0].second) ans = 1;
        while(beki(2, maxi) < v[i].second) maxi++;
        if(beki(2, maxi) != v[i].second) ans = 1;
        ans2 *= v[i].first;
    }
    ans += maxi;
    cout << ans2 << " " << ans << endl;
    return 0;
}