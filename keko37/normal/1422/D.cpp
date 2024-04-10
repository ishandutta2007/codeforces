#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 100005;
const llint INF = 1000000000000000000LL;

int n, m;
llint x[MAXN], y[MAXN], p[MAXN], dist[MAXN];
vector <pi> v[MAXN];
set <pi> st;

bool cmp (int i, int j) {
    return make_pair(x[i], y[i]) < make_pair(x[j], y[j]);
}

bool cmp2 (int i, int j) {
    return make_pair(y[i], x[i]) < make_pair(y[j], x[j]);
}

void add_edge (int a, int b, int w) {
    v[a].push_back({b, w});
    v[b].push_back({a, w});
}

void build () {
    sort(p + 1, p + 1 + m, cmp);
    for (int i = 1; i < m; i++) {
        int a = p[i], b = p[i + 1];
        llint w = x[b] - x[a];
        add_edge(a, b, w);
    }
    sort(p + 1, p + 1 + m, cmp2);
    for (int i = 1; i < m; i++) {
        int a = p[i], b = p[i + 1];
        llint w = y[b] - y[a];
        add_edge(a, b, w);
    }
    for (int i = 1; i <= m; i++) {
        v[m + 1].push_back({i, min(abs(x[i] - x[m + 1]), abs(y[i] - y[m + 1]))});
        v[i].push_back({m + 2, abs(x[i] - x[m + 2]) + abs(y[i] - y[m + 2])});
    }
    v[m + 1].push_back({m + 2, abs(x[m + 1] - x[m + 2]) + abs(y[m + 1] - y[m + 2])});
}

void dijkstra () {
    for (int i = 1; i <= m + 2; i++) {
        dist[i] = INF;
    }
    dist[m + 1] = 0;
    st.insert({0, m + 1});
    while (!st.empty()) {
        int x = st.begin() -> second;
        st.erase(st.begin());
        for (auto pp : v[x]) {
            llint sus = pp.first, w = pp.second;
            llint novi = dist[x] + w;
            if (novi < dist[sus]) {
                if (st.find({dist[sus], sus}) != st.end()) st.erase({dist[sus], sus});
                dist[sus] = novi;
                st.insert({dist[sus], sus});
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> x[m + 1] >> y[m + 1] >> x[m + 2] >> y[m + 2];
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
        p[i] = i;
    }
    build();
    dijkstra();
    cout << dist[m + 2];
    return 0;
}