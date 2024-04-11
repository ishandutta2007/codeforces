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
    vector<ll> ans(N);
    priority_queue<l_l, vector<l_l>, greater<l_l>> que;
    que.push({-N, 0});
    ll num = 0;
    while(!que.empty()) {
        auto tmp = que.top();
        que.pop();
        ll l = tmp.second;
        ll r = l - tmp.first;
        ll idx = (l+r-1)/2;
        ans[idx] = num;
        num++;
        //cerr << l << " " << r << " " << idx << endl;
        if(idx > l) {
            que.push({-(idx-l), l});
        }
        if(r > idx + 1) {
            que.push({-(r-idx - 1), idx + 1});
        }
    }
    for(int i = 0; i < N; i++) {
        cout << ans[i] + 1 << " ";
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