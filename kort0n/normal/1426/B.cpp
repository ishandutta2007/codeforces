#include <bits/stdc++.h>
//#include <atcoder/all>
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
    ll N, M;
    cin >> N >> M;
    bool ok = false;
    for(int i = 0; i < N; i++) {
        ll a[2][2];
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                cin >> a[j][k];
            }
        }
        if(a[0][1] == a[1][0]) ok = true;
    }
    if(M % 2 == 1) ok = false;
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}