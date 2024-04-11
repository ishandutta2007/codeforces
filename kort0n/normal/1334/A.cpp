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
void solve() {
    ll N;
    cin >> N;
    vector<l_l> v(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    string ans = "YES";
    for(int i = 0; i <= N - 1; i++) {
        if(v[i].first - v[i].second > v[i+1].first - v[i+1].second) ans = "NO";
        if(v[i].second > v[i+1].second) ans = "NO";
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}