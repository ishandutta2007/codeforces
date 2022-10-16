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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) {
        ll a, b;
        cin >> a >> b;
        if(a == 1) cout << 0 << endl;
        else if(a == 2) cout << b << endl;
        else cout << 2 * b << endl;
    }
    return 0;
}