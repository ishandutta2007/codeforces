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
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll maxi = -1e9;
    for(ll i = 0; i < N; i++) {
        chmax(ans, maxi - a[i]);
        chmax(maxi, a[i]);
    }
    ll tmp = 0;
    while(ans) {
        ans /= 2;
        tmp++;
    }
    cout << tmp << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}