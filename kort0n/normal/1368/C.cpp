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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<l_l> ans;
    N++;
    ans.push_back({0, 0});
    for(ll i = 1; i <= N; i++) {
        ans.push_back({i, i-1});
        ans.push_back({i-1, i});
        ans.push_back({i, i});
    }
    cout << ans.size() << endl;
    for(auto tmp : ans) cout << tmp.first << " " << tmp.second << endl;
    return 0;
}