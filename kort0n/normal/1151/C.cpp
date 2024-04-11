#include <bits/stdc++.h>
#define endl "\n"
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

const long long INF = 1e18;
const ll mod = 1000000007;

ll f(ll x) {
    vector<ll> num(2);
    ll sum = 0;
    for(int i = 0; sum < x; i++) {
        ll now = 1LL << i;
        chmin(now, x - sum);
        sum += now;
        num[i%2] += now;
    }
    ll ret = 0;
    num[0] %= mod;
    ret += num[0] * num[0];
    ret %= mod;
    num[1] %= mod;
    ret += num[1] * (num[1] + 1);
    ret %= mod;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll l, r;
    cin >> l >> r;
    ll ans = f(r) - f(l-1) + mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}