#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;
const llint INF = 1000000000000000000LL;

int n, m;
llint dist[MAXN][55];
vector <pi> v[MAXN];
set < pair <llint, pi> > st;

void dijkstra () {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 50; j++) {
            dist[i][j] = INF;
        }
    }
    dist[1][0] = 0;
    st.insert({0, {1, 0}});
    while (!st.empty()) {
        int x = (st.begin() -> second).first;
        int w = (st.begin() -> second).second;
        st.erase(st.begin());
        if (w == 0) {
            for (auto pp : v[x]) {
                int sus = pp.first, d = pp.second;
                int novi = dist[x][w];
                if (novi < dist[sus][d]) {
                    if (st.find({dist[sus][d], pp}) != st.end()) st.erase({dist[sus][d], pp});
                    dist[sus][d] = novi;
                    st.insert({dist[sus][d], pp});
                }
            }
        } else {
            for (auto pp : v[x]) {
                int sus = pp.first, d = pp.second;
                int novi = dist[x][w] + (w + d) * (w + d);
                if (novi < dist[sus][0]) {
                    if (st.find({dist[sus][0], {sus, 0}}) != st.end()) st.erase({dist[sus][0], {sus, 0}});
                    dist[sus][0] = novi;
                    st.insert({dist[sus][0], {sus, 0}});
                }
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dijkstra();
    for (int i = 1; i <= n; i++) {
        if (dist[i][0] < INF) cout << dist[i][0] << " "; else cout << -1 << " ";
    }
    return 0;
}