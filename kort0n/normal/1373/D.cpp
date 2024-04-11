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

ll f(vector<ll> b) {
    ll mini = 0;
    ll ret = 0;
    ll now = 0;
    for(int i = 0; i < b.size(); i++) {
        now += b[i];
        chmax(ret, now - mini);
        chmin(mini, now);
    }
    return ret;
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(i % 2 == 0) sum += a[i];
    }
    vector<ll> b;
    for(int i = 0; i + 1 < N; i += 2) {
        b.push_back(a[i+1] - a[i]);
    }
    ll tmp = f(b);
    b.clear();
    for(int i = 1; i + 1 < N; i += 2) {
        b.push_back(a[i] - a[i+1]);
    }
    chmax(tmp, f(b));
    ll ans = sum + tmp;
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