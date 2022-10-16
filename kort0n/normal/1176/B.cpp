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

ll a[105];
ll b[3];

void solve() {
    ll n;
    cin >> n;
    for(int i = 0; i < 3; i++) b[i] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i] % 3]++;
    }
    ll ans = min(b[1], b[2]);
    b[1] -= ans;
    b[2] -= ans;
    ans += b[0];
    ans += b[1] / 3;
    ans += b[2] / 3;
    cout << ans << endl;
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