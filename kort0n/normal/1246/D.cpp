#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
int p[100500];
int p2[100500];
vector<int> v;
vector<int> children[100050];
int DEEPEST = 0;
int depth[100050];
bool IsLongest[100050];
void dfs1(int now) {
    if(depth[DEEPEST] < depth[now]) DEEPEST = now;
    for(auto to : children[now]) {
        depth[to] = depth[now] + 1;
        dfs1(to);
    }
}

void dfs2(int now) {
    if(now == DEEPEST) IsLongest[now] = true;
    for(auto to : children[now]) {
        dfs2(to);
        IsLongest[now] |= IsLongest[to];
    }
    for(int i = 0; i < children[now].size(); i++) {
        if(IsLongest[children[now][i]]) {
            swap(children[now][i], children[now].back());
        }
    }
}

void dfs3(int now) {
    v.push_back(now);
    for(auto to : children[now]) {
        dfs3(to);
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i < N; i++) {
        cin >> p[i];
        children[p[i]].push_back(i);
    }
    dfs1(0);
    dfs2(0);
    dfs3(0);
    for(auto pos : v) cout << pos << " ";
    cout << endl;
    for(int i = 1; i < N; i++) {
        p2[v[i]] = v[i-1];
    }
    vector<int> ans;
    for(int i = 1; i < N; i++) {
        while(p2[v[i]] != p[v[i]]) {
            ans.push_back(v[i]);
            p2[v[i]] = p2[p2[v[i]]];
        }
    }
    cout << ans.size() << endl;
    for(auto val : ans) cout << val << " ";
    cout << endl;
    return 0;
}