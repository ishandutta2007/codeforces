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
int N;
vector<int> color;
vector<int> paths[200100];
vector<int> ans;
vector<int> children[200100];
vector<int> p;
vector<int> dp;

void dfs1(int now) {
    for(auto to : paths[now]) {
        if(to == p[now]) continue;
        p[to] = now;
        children[now].push_back(to);
        dfs1(to);
        dp[now] += max(dp[to], 0);
    }
    dp[now] += color[now] * 2 - 1;
}

void dfs2(int now) {
    for(auto to : children[now]) {
        ans[now] += max(dp[to], 0);
    }
    ans[now] += color[now] * 2 - 1;
    if(p[now] != -1) {
        int tmp = max(0, ans[now]);
        int tmp2 = ans[p[now]];
        tmp2 -= tmp;
        ans[now] += max(0, tmp2);
    }
    for(auto to : children[now]) {
        dfs2(to);
    }
}

int main() {
    cin >> N;
    color.resize(N);
    ans.resize(N);
    p.resize(N);
    dp.resize(N);
    for(int i = 0; i < N; i++) cin >> color[i];
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    p[0] = -1;
    dfs1(0);
    dfs2(0);
    for(int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}