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
vector<l_l> v;

ll dist[105000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        dist[i] = INF;
        ll q, w;
        cin >> q >> w;
        v.push_back({q, w});
        ans += w;
    }
    dist[0] = 0;
    sort(v.begin(), v.end());
    priority_queue<l_l, vector<l_l>, greater<l_l>> que;
    que.push({0, 0});
    while(que.size()) {
        auto tmp = que.top();
        ll from = tmp.second;
        ll c = tmp.first;
        que.pop();
        if(dist[from] != c) continue;
        if(from != 0) {
            if(chmin(dist[from-1], c)) que.push({c, from-1});
        }
        auto itr = lower_bound(v.begin(), v.end(), make_pair(v[from].first + v[from].second, INF));
        //cerr << from << " " << c << " " << itr - v.begin() << endl;
        if(itr != v.end()) {
            ll newc = c;
            ll to = itr - v.begin();
            newc += max(0LL, v[to].first - v[from].first - v[from].second);
            if(chmin(dist[to], newc)) que.push({newc, to});
        }
        if(itr != v.begin()) {
            itr--;
            ll newc = c;
            ll to = itr - v.begin();
            newc += max(0LL, v[to].first - v[from].first - v[from].second);
            if(chmin(dist[to], newc)) que.push({newc, to});
        }
    }
    assert(dist[N-1] != INF);
    ans += dist[N-1];
    cout << ans << endl;
    return 0;
}