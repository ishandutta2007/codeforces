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

void solve() {
    ll N, P, K;
    cin >> N >> P >> K;
    string S;
    cin >> S;
    ll x, y;
    cin >> x >> y;
    map<ll, ll> mp;
    ll idx = P - 1;
    for(ll i = 0; i + idx < N; i++) {
        if(S[i+idx] == '0') mp[i%K]++;
    }
    ll ans = INF;
    for(ll s = P - 1; s < N; s++) {
        ll nowans = (s - idx) * y;
        nowans += mp[(s - idx) % K] * x;
        chmin(ans, nowans);
        if(S[s] == '0') {
            mp[(s-idx)%K]--;
        }
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