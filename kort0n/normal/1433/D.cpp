#include <bits/stdc++.h>
//#include <atcoder/all>
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
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    vector<l_l> ans;
    for(int i = 0; i < N; i++) {
        if(a[i] == a[0]) continue;
        ans.push_back({0, i});
    }
    if(ans.empty()) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < N; i++) {
        if(a[i] == a[0]) continue;
        for(int j = 1; j < N; j++) {
            if(a[0] == a[j]) ans.push_back({i, j});
        }
        break;
    }
    cout << "YES" << endl;
    for(auto tmp : ans) {
        cout << tmp.first + 1 << " " << tmp.second + 1 << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}