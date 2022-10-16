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
    ll ans = INF;
    vector<ll> v;
    for(ll i = 1; i * i <= N; i++) {
        if(N % i == 0) {
            v.push_back(i);
            v.push_back(N / i);
        }
    }
    for(auto val : v) {
        if(val > K) continue;
        chmin(ans, N / val);
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