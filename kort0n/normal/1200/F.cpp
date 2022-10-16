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
const ll mod = 2520;
int N;
int k[1005];
int m[1005];
int e[1005][11];

bool circuit[1005][2600];
bool visiting[1005][2600];
bool visited[1005][2600];
int ans[1005][2600];
vector<i_i> invpathes[1005][2600];

void dfs(int i, int j) {
    if(visiting[i][j]) {
        circuit[i][j] = true;
        return;
    }
    if(visited[i][j]) return;
    visiting[i][j] = true;
    visited[i][j] = true;
    int NEW = j + k[i];
    NEW %= mod;
    invpathes[e[i][NEW % m[i]]][NEW].push_back({i, j});
    dfs(e[i][NEW % m[i]], NEW);
    visiting[i][j] = false;
}

void dfs2(int si, int sj, int i, int j, set<int> &st) {
    int NEW = j + k[i];
    NEW %= mod;
    st.insert(i);
    ans[si][sj] = st.size();
    if(e[i][NEW % m[i]] == si && NEW == sj) return;
    dfs2(si, sj, e[i][NEW % m[i]], NEW, st);
}

void dfs3(int i, int j) {
    //cerr << "searching on " << i << " " << j << " " << ans[i][j] << endl;
    for(int k = 0; k < invpathes[i][j].size(); k++) {
        int l = invpathes[i][j][k].first;
        int m = invpathes[i][j][k].second;
        if(ans[l][m] != 0) continue;
        ans[l][m] = ans[i][j];
        dfs3(l, m);
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> k[i];
        k[i] %= mod;
        k[i] += mod;
        k[i] %= mod;
    }
    for(int i = 1; i <= N; i++) {
        cin >> m[i];
        for(int j = 0; j < m[i]; j++) cin >> e[i][j];
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < mod; j++) {
            dfs(i, j);
            if(circuit[i][j]) {
                //cout << i << " " << j << endl;
            }
        }
    }
    set<int> Q;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < mod; j++) {
            if(!circuit[i][j]) continue;
            Q.clear();
            dfs2(i, j, i, j, Q);
            //cerr << i << " " << j << " " << ans[i][j] << endl;
            //cerr << "A" << endl;
            dfs3(i, j);
        }
    }
    //cerr << "A" << endl;
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        y %= mod;
        y += mod;
        y %= mod;
        cout << ans[x][y] << endl;
    }
    return 0;
}