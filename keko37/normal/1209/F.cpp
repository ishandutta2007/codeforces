#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const int INF = 1000000007;
const int LOG = 24;

int n, m, cnt = 1;
int dist[MAXN];
vector < pair <int, int> > v[MAXN], g[MAXN];
vector <int> red;
string s[MAXN];
set < pair <int, int> > st;
int dub[MAXN], z[MAXN], p[10][MAXN], par[LOG][MAXN], dp[MAXN], sol[MAXN];

string tos (int x) {
    string res = "";
    while (x > 0) {
        res += (char) (x % 10 + '0');
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

void dijkstra () {
    for (int i=1; i<=n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    st.insert({0, 1});
    while (!st.empty()) {
        int x = st.begin() -> second;
        st.erase(st.begin());
        if (x != 1) red.push_back(x);
        for (auto par : v[x]) {
            int sus = par.first;
            int edg = par.second;
            int val = dist[x] + s[edg].size();
            if (val < dist[sus]) {
                if (st.find({dist[sus], sus}) != st.end()) st.erase({dist[sus], sus});
                dist[sus] = val;
                st.insert({dist[sus], sus});
                g[sus].clear();
                g[sus].push_back({x, edg});
            } else if (val == dist[sus]) {
                g[sus].push_back({x, edg});
            }
        }
    }
}

int ubaci (int curr, string t) {
    int len = t.size();
    for (int i=0; i<len; i++) {
        int val = t[i] - '0';
        if (p[val][curr] == 0) {
            cnt++;
            p[val][curr] = cnt;
            dub[cnt] = 1 + dub[curr];
            z[cnt] = val;
            par[0][cnt] = curr;
            for (int j=1; j<LOG; j++) {
                par[j][cnt] = par[j-1][par[j-1][cnt]];
            }
        }
        curr = p[val][curr];
    }
    return curr;
}

int kth (int x, int k) {
    int pot = 0;
    while (k > 0) {
        if (k & 1) x = par[pot][x];
        pot++;
        k /= 2;
    }
    return x;
}

pair <int, int> lca (int a, int b) {
    if (dub[a] < dub[b]) swap(a, b);
    a = kth(a, dub[a] - dub[b]);
    if (a == b) return {-1, -1};
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[i][a] != par[i][b]) {
            a = par[i][a];
            b = par[i][b];
        }
    }
    return {a, b};
}

bool cmp (int x, int y) {
    pair <int, int> pii = lca(x, y);
    if (pii.first == -1) return 0;
    return z[pii.first] < z[pii.second];
}

void obradi (int x) {
    int ch = -1, tr = -1;
    for (auto par : g[x]) {
        int sus = par.first;
        int edg = par.second;
        int tmp = ubaci(dp[sus], s[edg]);
        if (ch == -1 || cmp(tmp, tr)) {
            ch = sus;
            tr = tmp;
        }
    }
    dp[x] = tr;
}

void ispis () {
    for (int i=2; i<=cnt; i++) {
        sol[i] = (sol[par[0][i]] * 10LL + z[i]) % INF;
    }
    for (int i=2; i<=n; i++) {
        cout << sol[dp[i]] << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back({b, i});
        v[b].push_back({a, i});
        s[i] = tos(i);
    }
    dijkstra();
    dp[1] = 1;
    for (auto x : red) obradi(x);
    ispis();
    return 0;
}