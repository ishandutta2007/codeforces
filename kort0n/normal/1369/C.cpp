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
    vector<ll> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<ll> w(K);
    for(int i = 0; i < K; i++) {
        cin >> w[i];
    }
    sort(a.begin(), a.end());
    sort(w.begin(), w.end());
    ll ans = 0;
    for(int i = 0; i < w.size(); i++) {
        ans += a[N-1-i];
        if(w[i] == 1) ans += a[N-1-i];
    }
    ll idx = 0;
    for(int i = K - 1; i >= 0; i--) {
        if(w[i] == 1) break;
        ans += a[idx];
        for(int j = 0; j < w[i] - 1; j++) idx++;
    }
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