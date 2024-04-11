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
    vector<ll> a(N), b(N), c(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) cin >> b[i];
    stack<int> sta;
    for(int i = N - 1; i >= 0; i--) {
        if(b[i] + c[i] > a[i]) sta.push(i);
    }
    while(!sta.empty()) {
        int now = sta.top();
        int i = now;
        int to = (i + 1) % N;
        sta.pop();
        ll delta = b[i] + c[i] - a[i];
        chmin(delta, b[i]);
        if(delta == 0) continue;
        //cerr << now << " " << to << " " << delta << endl;
        //cerr << "A" << a[now] << " " << b[now] << " " << c[now] << endl;
        b[i] -= delta;
        c[to] += delta;
        if(b[to] + c[to] > a[to]) sta.push(to);
    }
    for(int i = 0; i < N; i++) {
        if(b[i] + c[i] < a[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}