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
ll N;
ll A[105000];

void solve() {
    cin >> N;
    for(ll i = 0; i < N; i++) cin >> A[i];
    string ans = "YES";
    ll sum = 0;
    for(ll i = 0; i < N - 1; i++) {
        sum += A[i];
        if(sum <= 0) ans = "NO";
    }
    sum = 0;
    for(ll i = N - 1; i > 0; i--) {
        sum += A[i];
        if(sum <= 0) ans = "NO";
    }
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