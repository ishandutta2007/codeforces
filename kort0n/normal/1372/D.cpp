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
ll a[500000];
ll sum[500000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll total = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        total += a[i];
        a[i+N] = a[i];
    }
    vector<ll> v;
    v.push_back(0);
    for(int i = 0; i < 2 * N; i += 2) {
        ll tmp = v.back();
        tmp += a[i];
        v.push_back(tmp);
    }
    for(int i = 0; i < 2 * N; i += 2) {
        ll tmp = v.back();
        tmp += a[i];
        v.push_back(tmp);
    }
    ll ans = 0;
    for(int i = N/2; i <= 2 * N; i++) {
        chmax(ans, total - (v[i] - v[i-N/2]));
    }
    cout << ans << endl;
    return 0;
}