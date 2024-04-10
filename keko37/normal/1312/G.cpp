#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1000005;
const int INF = 1000000000;

int n, q;
int siz[MAXN], u[MAXN];
int p[26][MAXN];
vector <pi> v[MAXN * 2];
int dist[MAXN * 2];
set <pi> st;

void dfs (int x) {
    v[x].push_back({x + n + 1, 1});
    if (siz[x]) v[x + n + 1].push_back({x, 0});
    int curr = siz[x];
    for (int i = 0; i < 26; i++) {
        int sus = p[i][x];
        if (sus == 0) continue;
        dfs(sus);
        siz[x] += siz[sus];
        v[x].push_back({sus, 1});
        v[x + n + 1].push_back({sus + n + 1, curr});
        curr += siz[sus];
    }
}

void dijkstra () {
    for (int i = 1; i <= 2*n+2; i++) {
        dist[i] = INF;
    }
    st.insert({0, 0});
    while (!st.empty()) {
        int x = st.begin() -> second;
        st.erase(st.begin());
        for (auto par : v[x]) {
            int sus = par.first, w = par.second;
            int novi = dist[x] + w;
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
        int rod; char c;
        cin >> rod >> c;
        p[c - 'a'][rod] = i;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> u[i];
        siz[u[i]]++;
    }
    dfs(0);
    dijkstra();
    for (int i = 0; i < q; i++) {
        cout << dist[u[i]] << " ";
    }
    return 0;
}