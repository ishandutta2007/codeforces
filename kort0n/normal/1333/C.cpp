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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    map<ll, ll> mp;
    ll ans = 0;
    ll sum = 0;
    mp[0] = 1;
    ll L = 0;
    for(int i = 2; i <= N + 1; i++) {
        ll a;
        cin >> a;
        sum += a;
        chmax(L, mp[sum]);
        ans += i - L - 1;
        mp[sum] = i;
    }
    cout << ans << endl;
    return 0;
}