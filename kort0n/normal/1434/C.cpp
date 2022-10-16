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
__int128_t a, b, c, d;
__int128_t f(__int128_t timer) {
    __int128_t num = c / d;
    if(num > timer) num = timer;
    __int128_t rest = timer - num;
    __int128_t First = d*b;
    __int128_t Last = d * b * num;
    __int128_t delta = (First + Last) * num / 2;
    delta += rest * c * b;
    delta -= timer * a;
    return delta;
}

void solve() {
    ll tmp;
    cin >> tmp;
    a = tmp;
    cin >> tmp;
    b = tmp;
    cin >> tmp;
    c = tmp;
    cin >> tmp;
    d = tmp;
    if(b * c < a) {
        cout << -1 << endl;
        return;
    }
    __int128_t l = 0;
    __int128_t r = 1e12;
    while(r - l > 3) {
        __int128_t a = (2*l+r) / 3;
        __int128_t b = (l+2*r) / 3;
        if(f(a) < f(b)) r = b;
        else l = a;
    }
    __int128_t ans = 0;
    for(__int128_t x = l; x <= r; x++) {
        ans = max(ans, -f(x) + a);
    }
    cout << (ll)ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}