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
//const ll mod = 1000000007;

void solve() {
    ll N, K;
    cin >> N >> K;
    ll l[2], r[2];
    for(int i = 0; i < 2; i++) {
        cin >> l[i] >> r[i];
    }
    ll zero, one, base;
    if(l[0] > r[1]) {
        zero = l[0] - r[1];
        one =  (r[0] - l[0]) + (l[0] - l[1]);
        base = 0;
    } else if(l[1] > r[0]) {
        zero = l[1] - r[0];
        one =  (r[1] - l[1]) + (l[1] - l[0]);
        base = 0;
    } else {
        ll R = min(r[0], r[1]);
        ll L = max(l[0], l[1]);
        base = R - L;
        zero = 0;
        one = (r[1] - l[1]) + (r[0] - l[0]) - 2 * base;
    }
    if(base * N >= K) {
        cout << 0 << endl;
        return;
    }
    K -= base * N;
    ll ans = INF;
    for(int i = 1; i <= N; i++) {
        ll tmp = zero * i;
        ll num = min(K, i * one);
        ll rest = K - num;
        tmp += num;
        tmp += 2 * rest;
        chmin(ans, tmp);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}