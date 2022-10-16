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
    if(N <= 30) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if(N == 36) {
        cout << "6 10 15 5" << endl;
    } else if(N == 40) {
        cout << "6 10 22 2" << endl;
    } else if(N == 44) {
        cout << "6 10 26 2" << endl;
    } else {
        cout << "6 10 14 " << N - 6 - 10 - 14 << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}