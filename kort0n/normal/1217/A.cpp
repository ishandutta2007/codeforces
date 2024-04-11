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
    int s, i, e;
    cin >> s >> i >> e;
    if(s + e <= i) {
        cout << 0 << endl;
        return;
    }
    int ok = 0;
    int ng = e + 1;
    while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if(s + (e - mid) > mid + i) ok = mid;
        else ng = mid;
    }
    cout << ok + 1 << endl;
    return;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}