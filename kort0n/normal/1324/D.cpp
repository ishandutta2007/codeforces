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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> v(N);
    vector<ll> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        v[i] = a[i] - v[i];
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        auto itr = upper_bound(v.begin(), v.end(), -v[i]);
        ans += distance(itr, v.end());
    }
    for(int i = 0; i < N; i++) {
        if(v[i] > 0) ans--;
    }
    cout << ans / 2 << endl;
    return 0;
}