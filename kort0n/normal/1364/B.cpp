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
    vector<ll> p(N);
    for(int i = 0; i < N; i++) cin >> p[i];
    vector<ll> ans;
    ans.push_back(p[0]);
    for(int i = 1; i + 1 < N; i++) {
        if((p[i] - p[i-1]) * (p[i] - p[i+1]) > 0) ans.push_back(p[i]);
    }
    ans.push_back(p.back());
    cout << ans.size() << endl;
    for(auto val : ans) cout << val << " ";
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