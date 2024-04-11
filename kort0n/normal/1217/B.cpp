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
    int n, x;
    cin >> n >> x;
    int delta = -1;
    int maxi = 0;
    for(int j = 0; j < n; j++) {
        int d, h;
        cin >> d >> h;
        chmax(delta, d - h);
        chmax(maxi, d);
    }
    if(maxi >= x) {
        cout << 1 << endl;
        return;
    }
    if(delta <= 0) {
        cout << -1 << endl;
        return;
    }
    int ans = (x - maxi + delta - 1) / delta + 1;
    cout << ans << endl;
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