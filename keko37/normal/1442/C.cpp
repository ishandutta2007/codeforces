#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 200005;
const int MOD = 998244353;
const int LOG = 22;
const llint INF = 1000000000000000000LL;

int n, m;
llint dist[MAXN][LOG];
pi len[MAXN][2];
vector <int> v[MAXN], r[MAXN];
set < pair <llint, pi> > st;
set < pair <pi, pi> > st2;

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

void dijkstra_prva () {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 20; j++) {
            dist[i][j] = INF;
        }
    }
    dist[1][0] = 0;
    st.insert({0, {1, 0}});
    while (!st.empty()) {
        int x = (st.begin() -> second).first;
        int d = (st.begin() -> second).second;
        st.erase(st.begin());
        if (d < 20 && dist[x][d] + (1 << d) < dist[x][d + 1]) {
            if (st.find({dist[x][d + 1], {x, d + 1}}) != st.end()) st.erase({dist[x][d + 1], {x, d + 1}});
            dist[x][d + 1] = dist[x][d] + (1 << d);
            st.insert({dist[x][d + 1], {x, d + 1}});
        }
        if (d % 2 == 0) {
            for (auto sus : v[x]) {
                llint novi = dist[x][d] + 1;
                if (novi < dist[sus][d]) {
                    if (st.find({dist[sus][d], {sus, d}}) != st.end()) st.erase({dist[sus][d], {sus, d}});
                    dist[sus][d] = novi;
                    st.insert({dist[sus][d], {sus, d}});
                }
            }
        } else {
            for (auto sus : r[x]) {
                llint novi = dist[x][d] + 1;
                if (novi < dist[sus][d]) {
                    if (st.find({dist[sus][d], {sus, d}}) != st.end()) st.erase({dist[sus][d], {sus, d}});
                    dist[sus][d] = novi;
                    st.insert({dist[sus][d], {sus, d}});
                }
            }
        }
    }
}

void dijkstra_druga () {
    for (int i = 1; i <= n; i++) {
        for (int d = 0; d < 2; d++) {
            len[i][d] = {INF, 0};
        }
        if (dist[i][20] != INF) {
            len[i][0] = {0, dist[i][20]};
            st2.insert({len[i][0], {i, 0}});
        }
    }
    while (!st2.empty()) {
        int x = (st2.begin() -> second).first;
        int d = (st2.begin() -> second).second;
        st2.erase(st2.begin());
        pi bla = {len[x][d].first + 1, len[x][d].second};
        if (bla < len[x][!d]) {
            if (st2.find({len[x][!d], {x, !d}}) != st2.end()) st2.erase({len[x][!d], {x, !d}});
            len[x][!d] = bla;
            st2.insert({len[x][!d], {x, !d}});
        }
        if (d % 2 == 0) {
            for (auto sus : v[x]) {
                pi novi = {len[x][d].first, len[x][d].second + 1};
                if (novi < len[sus][d]) {
                    if (st2.find({len[sus][d], {sus, d}}) != st2.end()) st2.erase({len[sus][d], {sus, d}});
                    len[sus][d] = novi;
                    st2.insert({len[sus][d], {sus, d}});
                }
            }
        } else {
            for (auto sus : r[x]) {
                pi novi = {len[x][d].first, len[x][d].second + 1};
                if (novi < len[sus][d]) {
                    if (st2.find({len[sus][d], {sus, d}}) != st2.end()) st2.erase({len[sus][d], {sus, d}});
                    len[sus][d] = novi;
                    st2.insert({len[sus][d], {sus, d}});
                }
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        r[b].push_back(a);
    }
    dijkstra_prva();
    llint mn = INF;
    for (int d = 0; d <= 20; d++) {
        mn = min(mn, dist[n][d]);
    }
    if (mn != INF) {
        cout << mn % MOD;
        return 0;
    }
    dijkstra_druga();
    pi res = min(len[n][0], len[n][1]);
    int sol = res.second % MOD;
    int pot = 1 << 20;
    for (int i = 0; i < res.first; i++) {
        sol = add(sol, pot);
        pot = mul(pot, 2);
    }
    cout << sol;
    return 0;
}