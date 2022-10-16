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
    vector<ll> a(2 * N);
    for(int i = 0; i < 2 * N; i++) {
        cin >> a[i];
        if(a[i] == 2) a[i] = -1;
    }
    map<ll, ll> Left, Right;
    ll sum = 0;
    Left[0] = 0;
    for(int i = 0; i < N; i++) {
        sum += a[i];
        Left[sum] = i + 1;
    }
    sum = 0;
    Right[0] = 0;
    for(int i = 0; i < N; i++) {
        sum += a[2 * N - 1 - i];
        Right[sum] = i + 1;
    }
    ll ans = 0;
    for(ll i = -N; i <= N; i++) {
        if(Left.count(i) == 0) continue;
        if(Right.count(-i) == 0) continue;
        chmax(ans, Left[i] + Right[-i]);
    }
    cout << 2 * N - ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}