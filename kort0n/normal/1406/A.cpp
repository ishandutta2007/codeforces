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
    ll N;
    cin >> N;
    map<ll, ll> mp;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        mp[a]++;
    }
    ll ans = 0;
    for(int i = 0; i <= 200; i++) {
        if(mp[i] <= 1) {
            ans += i;
            break;
        }
    }
    for(int i = 0; i <= 200; i++) {
        if(mp[i] <= 0) {
            ans += i;
            break;
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