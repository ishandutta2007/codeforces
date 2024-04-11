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

bool AllZero(vector<ll> v) {
    for(auto c : v) {
        if(c != 0) return false;
    }
    return true;
}

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    if(K == 1) {
        sort(a.begin(), a.end());
        if(a[0] != a[N-1]) cout << -1 << endl;
        else cout << 1 << endl;
        return;
    }
    ll ans = 0;
    while(true) {
        if(AllZero(a)) {
            cout << ans << endl;
            return;
        }
        ans++;
        ll now = -1;
        ll num = 0;
        for(int i = 0; i < N; i++) {
            if(now != a[i] and num + 1 <= K) {
                num++;
                now = a[i];
            }
            a[i] -= now;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}