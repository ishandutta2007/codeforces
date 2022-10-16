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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x, y, z;
    cin >> x >> y >> z;
    if(x / z + y / z == (x + y) / z) {
        cout << (x + y) / z << " " << 0 << endl;
    } else {
        cout << (x + y) / z << " " << min(z - x % z, z - y % z) << endl;
    }
    return 0;
}