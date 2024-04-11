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
map<ll, ll> mp;

void solve() {
    mp.clear();
    ll N, X;
    cin >> N >> X;
    ll maxi = 0;
    ll mini = 0;
    string S;
    cin >> S;
    ll now = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '0') now++;
        else now--;
        mp[now]++;
        chmax(maxi, now);
        chmin(mini, now);
    }
    if(now == 0) {
        if(maxi >= X and X >= mini) cout << "-1" << endl;
        else cout << 0 << endl;
        return;
    }
    //cerr << now << " " << maxi << " " << mini << endl;
    ll ans = 0;
    if(X == 0) ans++;
    ll tmp = 0;
    if(now > 0) {
        ll delta = X - maxi;
        chmax(delta, 0LL);
        tmp += delta / now * now;
    }
    if(now < 0) {
        ll delta = mini - X;
        chmax(delta, 0LL);
        tmp -= delta / (-now) * (-now);
    }
    while(true) {
        if(tmp + maxi < X and tmp < 0) break;
        if(tmp + mini > X and tmp > 0) break;
        ans += mp[X - tmp];
        tmp += now;
    }
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}