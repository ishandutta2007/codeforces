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
ll a[2][201000];
ll N;
ll ans;

void solve() {
    cin >> N;
    vector<ll> ans;
    map<ll, vector<l_l>> mp;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
            a[i][j]--;
            mp[a[i][j]].push_back({i, j});
        }
    }
    for(auto tmp : mp) {
        if(tmp.second.size() > 2) {
            cout << -1 << endl;
            return;
        }
    }
    set<ll> searched;
    for(int i = 0; i < N; i++) {
        if(searched.find(i) != searched.end()) continue;
        vector<ll> ok, ng;
        ll now = i;
        ll up = a[0][i];
        ll down = a[1][i];
        while(true) {
            ll nxt;
            if(mp[down][0].second == now) nxt = mp[down][1].second;
            else nxt = mp[down][0].second;
            now = nxt;
            searched.insert(now);
            if(a[0][now] == down) ok.push_back(now);
            else ng.push_back(now);
            up = down;
            if(a[0][now] == up) down = a[1][now];
            else down = a[0][now];
            if(now == i) break;
        }
        if(ok.size() > ng.size()) swap(ok, ng);
        for(auto tmp : ok) ans.push_back(tmp);
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i] + 1;
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