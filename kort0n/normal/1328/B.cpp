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
    K = N * (N - 1) / 2 - K;
    ll one = 0;
    while(true) {
        if(K < N - one - 1) break;
        K -= N - one - 1;
        one++;
    }
    ll two = one + K + 1;
    for(int i = 0; i < N; i++) {
        if(i == one or i == two) cout << "b";
        else cout << "a";
    }
    cout << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}