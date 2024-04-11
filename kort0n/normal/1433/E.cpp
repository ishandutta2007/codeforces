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
ll Factorial[21];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Factorial[0] = 1;
    for(ll i = 1; i <= 20; i++) {
        Factorial[i] = Factorial[i-1] * i;
    }
    ll N;
    cin >> N;
    ll ans = Factorial[N] / Factorial[N/2] / Factorial[N/2];
    ans *= Factorial[N/2-1] * Factorial[N/2-1];
    ans /= 2;
    cout << ans << endl;
    return 0;
}