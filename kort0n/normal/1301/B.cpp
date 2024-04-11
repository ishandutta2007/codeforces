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
    int N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    ll maxi = 0;
    ll mini = 1e9;
    for(int i = 0; i < N; i++) {
        if(a[i] == -1) continue;
        if(i > 0 and a[i-1] == -1) {
            chmax(maxi, a[i]);
            chmin(mini, a[i]);
        }
        if(i < N - 1 and a[i+1] == -1) {
            chmax(maxi, a[i]);
            chmin(mini, a[i]);
        }
    }
    ll k = (maxi + mini) / 2;
    for(int i = 0; i < N; i++) {
        if(a[i] == -1) a[i] = k;
    }
    ll ans = 0;
    for(int i = 0; i + 1 < N; i++) {
        chmax(ans, abs(a[i] - a[i+1]));
    }
    cout << ans << " " << k << endl;
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