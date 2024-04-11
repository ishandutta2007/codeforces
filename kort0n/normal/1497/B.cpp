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
    ll N, M;
    cin >> N >> M;
    map<ll, ll> mp;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        a %= M;
        mp[a]++;
    }
    ll ans = 0;
    for(auto tmp : mp) {
        if(tmp.second == 0) continue;
        if(tmp.first == 0 or tmp.first * 2 == M) {
            ans++;
            continue;
        }
        ll d = tmp.first;
        ll a = mp[d];
        ll b = mp[M-d];
        mp[d] = 0;
        mp[M-d] = 0;
        if(a < b) swap(a, b);
        ans++;
        a -= (b + 1);
        if(a >= 1) ans += a;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}