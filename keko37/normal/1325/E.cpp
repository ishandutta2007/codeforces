#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1e6 + 5;

int n, sol = MAXN;
int r[MAXN], cnt[MAXN], bio[MAXN], dist[MAXN], doso[MAXN];
vector <int> v, g[MAXN];
queue <int> q;
vector <pi> edg;

void precompute () {
    for (int i = 2; i < MAXN; i++) {
        if (r[i] == 0) v.push_back(i), r[i] = i;
        for (int j = 0; j < v.size() && v[j] <= r[i] && v[j] * i < MAXN; j++) {
            r[v[j] * i] = v[j];
        }
    }
}

void factor (int x) {
    vector <int> e;
    int val = 1;
    while (x > 1) {
        int p = r[x], br = 0;
        while (x % p == 0) {
            br++;
            x /= p;
        }
        if (br % 2 == 1) e.push_back(p), val *= p;
    }
    cnt[val]++;
    if (cnt[val] >= 2) sol = min(sol, 2);
    if (e.size() == 0) sol = min(sol, 1);
    if (e.size() == 1) {
        bio[e[0]] = e[0];
        dist[e[0]] = 0;
        q.push(e[0]);
    } else if (e.size() == 2) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
        edg.push_back({e[0], e[1]});
    }
}

void bfs () {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto sus : g[x]) {
            if (bio[sus] == 0) {
                bio[sus] = bio[x];
                dist[sus] = 1 + dist[x];
                q.push(sus);
            } else if (bio[sus] != bio[x]) {
                sol = min(sol, dist[x] + 3 + dist[sus]);
            }
        }
    }
}

void check (int x) {
    for (auto p : v) bio[p] = 0, dist[p] = MAXN, doso[p] = 0;
    bio[x] = 1; dist[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto sus : g[x]) {
            if (!bio[sus]) {
                doso[sus] = x;
                bio[sus] = 1;
                dist[sus] = 1 + dist[x];
                q.push(sus);
            }
        }
    }
    for (auto par : edg) {
        int a = par.first, b = par.second;
        if (a != doso[b] && b != doso[a]) {
            sol = min(sol, dist[a] + dist[b] + 1);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    for (auto p : v) dist[p] = MAXN;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        factor(x);
    }
    if (sol <= 2) {
        cout << sol;
        return 0;
    }
    bfs();
    for (auto p : v) {
        if (p > 1000) break;
        check(p);
    }
    if (sol == MAXN) cout << -1; else cout << sol;
    return 0;
}