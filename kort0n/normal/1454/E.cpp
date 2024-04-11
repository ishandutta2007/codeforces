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
ll N;
vector<ll> edges[210000];
ll ans;
ll d[201000];

void solve() {
    ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        edges[i].clear();
        d[i] = 0;
    }
    for(int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
        d[a]++;
        d[b]++;
    }
    ans = N * (N - 1);
    map<ll, ll> mp;
    queue<ll> que;
    for(int i = 0; i < N; i++) {
        if(d[i] == 1) que.push(i);
    }
    while(!que.empty()) {
        auto now = que.front();
        que.pop();
        mp[now]++;
        for(auto to : edges[now]) {
            d[to]--;
            if(d[to] >= 1) {
                mp[to] += mp[now];
                mp[now] = 0;
                if(d[to] == 1) que.push(to);
            }
        }
        assert(mp[now] == 0);
    }
    //cerr << "-------------" << endl;
    for(auto tmp : mp) {
        //cerr << tmp.first << ", " << tmp.second << endl;
        ans -= tmp.second * (tmp.second + 1) / 2;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}