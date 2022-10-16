#include <bits/stdc++.h>
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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll All = n * (n + 1) / 2;
    ll mini = (n - m) / (m + 1);
    ll maxi = mini + 1;
    ll maxinum = (n - m) % (m + 1);
    ll mininum = m + 1 - maxinum;
    ll rest = maxinum * maxi * (maxi + 1) / 2;
    rest += mininum * mini * (mini + 1) / 2;
    cout << All - rest << endl;
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