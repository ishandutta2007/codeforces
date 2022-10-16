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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

void solve() {
    ll n;
    cin >> n;
    ll timer = 0;
    while(n % 5 == 0) {
        n /= 5;
        n *= 4;
        timer++;
    }
    while(n % 3 == 0) {
        n /= 3;
        n *= 2;
        timer++;
    }
    while(n % 2 == 0) {
        n /= 2;
        timer++;
    }
    if(n != 1) {
        cout << -1 << endl;
    } else {
        cout << timer << endl;
    }
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