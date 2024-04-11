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
    ll n, a, b;
    cin >> n >> a >> b;
    string S;
    cin >> S;
    ll l = -1;
    ll ans = a * n + b * (n + 1);
    for(ll i = 0; i < S.size(); i++) {
        if(S[i] == '0') continue;
        if(l == -1) {
            ans += a;
            ans += b;
            ans += b;
            l = i;
            continue;
        }
        ll now = (i - l) * b;
        chmin(now, 2 * b + 2 * a);
        //cerr << l << " " << i << " " << now << endl;
        ans += now;
        l = i;
    }
    if(l == -1) {
    } else {
        ans += a;
    }
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