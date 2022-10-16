#include <bits/stdc++.h>
//#include <atcoder/all>
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
//const ll mod = 1000000007;
ll a[105000];
ll b[105000];
ll f(ll x) {
    if(x % 2 == 0) return x / 2;
    x++;
    return x / 2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i-1];
        ans += max(0LL, b[i]);
    }
    if(a[1] < 0) ans += a[1];
    cout << f(ans) << endl;
    ll Q;
    cin >> Q;
    for(int q = 0; q < Q; q++) {
        ll l, r, x;
        cin >> l >> r >> x;
        ans -= max(0LL, b[l]);
        b[l] += x;
        ans += max(0LL, b[l]);
        if(l == 1) {
            ans -= min(a[1], 0LL);
            a[1] += x;
            ans += min(a[1], 0LL);
        }
        r++;
        if(r <= N) {
            ans -= max(0LL, b[r]);
            b[r] -= x;
            ans += max(0LL, b[r]);
        }
        cout << f(ans) << endl;
    }
    return 0;
}