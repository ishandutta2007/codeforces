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
ll beki[25];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    beki[0] = 1;
    for(ll i = 1; i <= 24; i++) beki[i] = beki[i-1] * 2;
    ll n, l, r;
    cin >> n >> l >> r;
    ll sum = 0;
    for(int i = 0; i < l; i++) {
        sum += beki[i];
    }
    cout << sum + (n - l) << " ";
    for(int i = l; i < r; i++) sum += beki[i];
    cout << sum + (n - r) * beki[r-1] << endl;
    return 0;
}