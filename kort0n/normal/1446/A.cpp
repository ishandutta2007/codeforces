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
    ll N, W;
    cin >> N >> W;
    vector<l_l> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), greater<l_l>());
    vector<ll> ans;
    ll nowW = 0;
    for(auto tmp : v) {
        if(tmp.first + nowW <= W) {
            nowW += tmp.first;
            ans.push_back(tmp.second);
        }
    }
    if((W + 1) / 2 <= nowW) {
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto tmp : ans) {
            cout << tmp + 1 << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
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