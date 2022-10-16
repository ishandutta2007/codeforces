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

const long long INF = 1e11;
//const ll mod = 1000000007;
vector<l_l> v[2][2];
ll now = 0;
multiset<ll> low, high;
ll lowsz;

void f() {
    while(low.size() > lowsz) {
        auto itr = low.end();
        itr--;
        now -= *itr;
        auto val = *itr;
        low.erase(itr);
        high.insert(val);
    }
    while(low.size() < lowsz) {
        if(high.empty()) break;
        auto itr = high.begin();
        auto val = *itr;
        now += val;
        high.erase(itr);
        low.insert(val);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        ll t, a, b;
        cin >> t >> a >> b;
        v[a][b].push_back({t, i});
    }
    ll ans = INF;
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= 1; j++) {
            while(v[i][j].size() < N) {
                v[i][j].push_back({INF, -1});
            }
            sort(v[i][j].begin(), v[i][j].end());
        }
    }
    int ansbothnum = K;
    for(int i = 0; i < K; i++) {
        now += v[1][1][i].first;
    }
    for(int i = K; i < v[1][1].size(); i++) {
        high.insert(v[1][1][i].first);
    }
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= 1; j++) {
            if(i == 1 and j == 1) continue;
            for(auto tmp : v[i][j]) high.insert(tmp.first);
        }
    }
    lowsz = M - K;
    f();
    if(low.size() == lowsz) chmin(ans, now);
    for(int i = 0; i < K; i++) {
        lowsz--;
        if(lowsz < 0) break;
        ll val = v[1][1][K-1-i].first;
        now -= val;
        if(!high.empty() and *high.begin() <= val) {
            high.insert(val);
        } else {
            low.insert(val);
            now += val;
        }
        for(int j = 0; j < 2; j++) {
            ll val = v[j][1-j][i].first;
            now += val;
            auto itr = high.lower_bound(val);
            if(itr != high.end() and *itr == val) {
                high.erase(itr);
            } else {
                auto itr = low.lower_bound(val);
                now -= val;
                low.erase(itr);
            }
        }
        f();
        //cerr << i << " " << lowsz << " " << low.size() << " " << now << endl;
        if(low.size() == lowsz) {
            if(chmin(ans, now)) {
                ansbothnum = K - 1 - i;
            }
        }
    }
    if(ans >= INF) ans = -1;
    cout << ans << endl;
    if(ans == -1) return 0;
    vector<int> ansv;
    for(int i = 0; i < ansbothnum; i++) {
        ansv.push_back(v[1][1][i].second);
    }
    for(int i = 0; i < K - ansbothnum; i++) {
        for(int j = 0; j < 2; j++) {
            ansv.push_back(v[j][1-j][i].second);
        }
    }
    priority_queue<l_l, vector<l_l>, greater<l_l>> que;
    for(int i = ansbothnum; i < v[1][1].size(); i++) {
        que.push(v[1][1][i]);
    }
    for(int j = 0; j < 2; j++) {
        for(int i = K - ansbothnum; i < v[j][1-j].size(); i++) {
            que.push(v[j][1-j][i]);
        }
    }
    for(auto tmp : v[0][0]) que.push(tmp);
    while(ansv.size() < M) {
        auto tmp = que.top();
        que.pop();
        ansv.push_back(tmp.second);
    }
    for(auto tmp : ansv) {
        cout << tmp + 1 << " ";
    }
    cout << endl;
    return 0;
}