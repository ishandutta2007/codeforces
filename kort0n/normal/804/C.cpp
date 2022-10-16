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
ll N, M;
vector<ll> paths[300100];
vector<ll> st[300100];
vector<ll> inv[300100];
ll ans[300100];
ll depth[300100];
ll root[300010];
vector<ll> colors[300010];

int checked[300100];

void dfs(int now, int from) {
    for(auto to : paths[now]) {
        if(to == from) continue;
        depth[to] = depth[now] + 1;
        dfs(to, now);
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < M; i++) ans[i] = -1;
    for(int i = 0; i < 3e5; i++) checked[i] = -1;
    for(int i = 0; i < N; i++) {
        ll s;
        cin >> s;
        for(int j = 0; j < s; j++) {
            ll a;
            cin >> a;
            a--;
            st[i].push_back(a);
            inv[a].push_back(i);
        }
    }
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dfs(0, -1);
    vector<l_l> v;
    for(int i = 0; i < M; i++) {
        if(inv[i].empty()) continue;
        ll d = 1e9;
        for(auto tmp : inv[i]) {
            if(chmin(d, depth[tmp])) root[i] = tmp;
        }
        v.push_back({d, i});
    }
    sort(v.begin(), v.end());
    for(auto tmp : v) {
        int nowm = tmp.second;
        //cerr << nowm << endl;
        if(checked[root[nowm]] == -1) {
            for(auto tmp : st[root[nowm]]) {
                if(ans[tmp] == -1) continue;
                colors[root[nowm]].push_back(ans[tmp]);
            }
            colors[root[nowm]].push_back(1e9);
            sort(colors[root[nowm]].begin(), colors[root[nowm]].end());
        }
        //cerr << root[nowm] << endl;
        //cerr << colors[root[nowm]].size() << endl;
        while(true) {
            checked[root[nowm]]++;
            auto itr = lower_bound(colors[root[nowm]].begin(), colors[root[nowm]].end(), checked[root[nowm]]);
            if(*itr != checked[root[nowm]]) {
                ans[nowm] = checked[root[nowm]];
                break;
            }
        }
    }
    ll maxval = 0;
    for(int i = 0; i < M; i++) {
        chmax(maxval, ans[i]);
    }
    cout << maxval + 1 << endl;
    for(int i = 0; i < M; i++) {
        if(ans[i] == -1) ans[i] = 0;
        if(i != 0) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;
    return 0;
}