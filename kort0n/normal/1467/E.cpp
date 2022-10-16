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
ll A[201000];
vector<ll> edges[201000];
ll p[201000];
ll imos[201000];
map<ll, ll> mp[201000];
ll ans;
map<ll, ll> cnt;
void merge(int i, int j) {
    if(mp[i].size() < mp[j].size()) swap(mp[i], mp[j]);
    for(auto tmp : mp[j]) {
        mp[i][tmp.first] += tmp.second;
    }
    mp[j].clear();
}

void dfs1(int now) {
    vector<int> children;
    for(auto to : edges[now]) {
        if(to == p[now]) continue;
        p[to] = now;
        children.push_back(to);
        dfs1(to);
    }
    vector<ll> v;
    for(int i = 0; i < children.size(); i++) {
        int to = children[i];
        if(mp[to].count(A[now])) {
            v.push_back(i);
        }
        merge(now, to);
    }
    mp[now][A[now]]++;
    if(mp[now][A[now]] != cnt[A[now]]) v.push_back(-1);
    /*
    cerr << "------" << now << "-------" << endl;
    for(auto tmp : v) cerr << tmp << " ";
    cerr << endl;
    */
    if(v.size() == 0) return;
    if(v.size() >= 2) {
        imos[0]++;
        return;
    }
    if(v[0] == -1) {
        imos[now]++;
    } else {
        imos[0]++;
        imos[children[v[0]]]--;
    }
}

void dfs2(int now) {
    if(imos[now] == 0) ans++;
    for(auto to : edges[now]) {
        if(to == p[now]) continue;
        imos[to] += imos[now];
        dfs2(to);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    p[0] = -1;
    dfs1(0);
    dfs2(0);
    cout << ans << endl;
    return 0;
}