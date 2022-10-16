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
const ll mod = 1000000007;
ll N;
ll x[501000];
ll num[60];

void solve() {
    cin >> N;
    for(int i = 0; i < 60; i++) num[i] = 0;
    for(int i = 0; i < N; i++) {
        cin >> x[i];
        for(int j = 0; j < 60; j++) {
            if(x[i] & (1LL << j)) num[j]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        ll AND = 0;
        ll OR = 0;
        for(int j = 0; j < 60; j++) {
            ll factor = ((1LL << j) % mod);
            if(x[i] & (1LL << j)) {
                OR += N * factor;
                AND += num[j] * factor;
            } else {
                OR += num[j] * factor;
            }
            OR %= mod;
            AND %= mod;
        }
        ans += OR * AND;
        ans %= mod;
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