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
    map<ll, vector<ll>> mp;
    for(int i = 0; i < N; i++) cin >> a[i];
    vector<ll> ans(N + 1);
    for(int i = 0; i <= N; i++) ans[i] = INF;
    for(int i = 0; i < N; i++) {
        if(mp.count(a[i]) == 0) {
            mp[a[i]].push_back(-1);
        }
        mp[a[i]].push_back(i);
    }
    for(auto tmp : mp) {
        auto val = tmp.first;
        auto v = tmp.second;
        v.push_back(N);
        ll minimum = 1;
        for(int i = 1; i < v.size(); i++) {
            chmax(minimum, v[i] - v[i-1]);
        }
        chmin(ans[minimum], val);
    }
    for(int i = 1; i <= N; i++) {
        chmin(ans[i], ans[i-1]);
        if(ans[i] == INF) cout << -1 << " ";
        else cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}