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
    vector<ll> a(N), b(N);
    for(int i = 0; i < N; i++) cin >> a[i] >> b[i];
    ll sum = 0;
    ll ans = 1e18;
    for(int i = 0; i < N; i++) {
        sum += max(0LL, a[i] - b[(i+N-1)%N]);
    }
    for(int i = 0; i < N; i++) {
        ll now = sum;
        now -= max(0LL, a[i] - b[(i+N-1)%N]);
        now += a[i];
        chmin(ans, now);
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