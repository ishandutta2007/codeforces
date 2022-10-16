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
    ll A;
    cin >> A;
    if(A == 1) {
        cout << "1 1" << endl;
        cout << 1 << endl;
        return 0;
    } else {
        cout << 2 * A - 1 << " " << 2 << endl;
        cout << 1 << " " << 2 << endl;
    }
    return 0;
}