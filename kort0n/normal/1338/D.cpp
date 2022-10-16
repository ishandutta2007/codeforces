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
ll dp[105000][2];
vector<ll> paths[105000];
ll ans;

void dfs(int now, int from) {
    vector<l_l> v[2];
    vector<int> children;
    ll tmpans = 0;
    ll tmp1, tmp2;
    for(auto to : paths[now]) {
        if(to == from) continue;
        children.push_back(to);
        dfs(to, now);
    }
    for(auto to : children) {
        for(int j = 0; j < 2; j++) {
            v[j].push_back({dp[to][j], to});
        }
    }
    for(int j = 0; j < 2; j++) {
        sort(v[j].begin(), v[j].end(), greater<l_l>());
    }
    //1
    tmpans = 1;
    if(v[1].size() >= 1) tmpans += v[1][0].first;
    if(v[1].size() >= 2) tmpans += v[1][1].first;
    tmp2 = tmpans;
    chmax(ans, tmpans);
    //2
    tmpans = 1;
    if(v[1].size() >= 1) {
        tmpans += v[1][0].first;
    }
    dp[now][0] = tmpans;
    //3
    tmpans = 0;
    if(v[0].size() >= 1) {
        tmpans = max(v[0][0].first, v[1][0].first);
    }
    if(v[0].size() >= 1) {
        tmpans += v[0].size() - 1;
    }
    dp[now][1] = tmpans;
    //4
    if(v[0].size() >= 2) {
        tmpans = 0;
        ll tmpval = 0;
        chmax(tmpval, v[0][0].first + v[0][1].first);
        chmax(tmpval, v[1][0].first + v[1][1].first);
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                if(v[0][i].second == v[1][j].second) continue;
                chmax(tmpval, v[0][i].first + v[1][j].first);
            }
        }
        tmpans = tmpval + paths[now].size() - 2;
        tmp1 = tmpans;
        chmax(ans, tmpans);
    } else {
        tmp1 = 0;
    }
    //cerr << now + 1 << " " << dp[now][0] << " " << dp[now][1] << " " << tmp1 << " " << tmp2 << endl;
}

int main() {
    ll N;
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    ll root = 0;
    for(int i = 0; i < N; i++) {
        if(paths[i].size() >= 2) root = i;
    }
    dfs(root, -1);
    cout << ans << endl;
    return 0;
}