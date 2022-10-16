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
ll f(ll x) {
    if(x < 10) return x;
    return (x % 10) + f(x / 10);
}
void solve() {
    ll N, S;
    cin >> N >> S;
    if(f(N) <= S) {
        cout << 0 << endl;
        return;
    }
    ll a = 1;
    ll iniN = N;
    while(true) {
        a *= 10;
        if(N % a == 0) continue;
        N = (N / a) * a;
        N += a;
        if(f(N) <= S) {
            cout << N - iniN << endl;
            return;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}