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
    ll N, X;
    cin >> N >> X;
    vector<ll> a(N);
    vector<ll> v;
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
        if(a[i] % X != 0) v.push_back(i);
    }
    sum %= X;
    if(sum != 0) {
        cout << N << endl;
        return;
    }
    if(v.empty()) {
        cout << -1 << endl;
        return;
    }
    ll ans = N - min(v[0] + 1, N - v.back());
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}