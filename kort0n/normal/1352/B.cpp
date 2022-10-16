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
    if(N % 2 == K % 2 and N >= K) {
        cout << "YES" << endl;
        cout << N - K + 1;
        for(int i = 0; i < K - 1; i++) {
            cout << " " << 1;
        }
        cout << endl;
        return;
    }
    if(N % 2 == 0 and N >= K * 2) {
        cout << "YES" << endl;
        cout << N - K * 2 + 2;
        for(int i = 0; i < K - 1; i++) {
            cout << " " << 2;
        }
        cout << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}