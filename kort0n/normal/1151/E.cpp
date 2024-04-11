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

ll a[100500];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<l_l> v(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        //v[i].first = a[i];
        //v[i].second = i;
    }
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        ans += (N - a[i] + 1) * a[i];
    }
    for(int i = 0; i + 1 < N; i++) {
        ll M = max(a[i], a[i+1]);
        ll m = min(a[i], a[i+1]);
        ans -= (N - M + 1) * m;
    }
    cout << ans << endl;
    /*sort(v.begin(), v.end(), greater<l_l>());
    ll ans = 0;
    for(auto tmp : v) {

    }
    */
    return 0;
}