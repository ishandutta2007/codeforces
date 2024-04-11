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
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    ll ans = 0;
    for(ll s = 0; s <= 2 * N; s++) {
        {
            map<ll, ll> mp;
            ll now = 0;
            for(int i = 0; i < N; i++) {
                if(mp[s-a[i]] >= 1) {
                    mp[s-a[i]]--;
                    now++;
                } else {
                    mp[a[i]]++;
                }
            }
            chmax(ans, now);
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