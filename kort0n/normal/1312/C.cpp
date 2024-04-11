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
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    map<ll, ll> mp;
    string ans = "YES";
    for(int i = 0; i < N; i++) {
        ll d = 1;
        for(ll timer = 0; ; timer++) {
            //cerr << i << " " << a[i] << " " << d << endl;
            if(a[i] == 0) break;
            if(ans == "NO") break;
            if(a[i] % (d * K) == 0) {
                d *= K;
                continue;
            }
            if((a[i] % (d * K)) != d) ans = "NO";
            if(mp[timer]) ans = "NO";
            mp[timer]++;
            a[i] -= d;
            d *= K;
        }
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