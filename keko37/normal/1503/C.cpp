#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;
const int INF = 1000000007;

int n;
vector <pi> r;
vector <pi> v[MAXN];
llint dist[MAXN];
set < pair <llint, int> > st;

void dijkstra () {
    for (int i = 0; i < n; i++) {
        dist[i] = (llint) 1e18;
    }
    dist[0] = 0;
    st.insert({0, 0});
    while (!st.empty()) {
        int x = st.begin() -> second;
        st.erase(st.begin());
        for (auto pp : v[x]) {
            int sus = pp.first;
            llint w = pp.second;
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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, c;
        cin >> a >> c;
        r.push_back({a, c});
    }
    sort(r.begin(), r.end());
    for (int i = 0; i < n; i++) {
        if (i > 0) v[i].push_back({i - 1, 0});
        int a = r[i].first, c = r[i].second;
        int ind = upper_bound(r.begin(), r.end(), make_pair(a + c, INF)) - r.begin();
        if (ind < n) v[i].push_back({ind, r[ind].first - a - c});
        if (ind > 0) v[i].push_back({ind - 1, 0});
    }
    dijkstra();
    llint sol = dist[n - 1];
    for (auto pp : r) sol += pp.second;
    cout << sol;
    return 0;
}