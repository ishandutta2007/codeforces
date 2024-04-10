#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

const int inf = 1e9;

struct cover
{
    int a, b, c, d;
    cover() : a(0), b(0), c(0), d(0) {}
    cover(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
};

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n);
    vector<vector<int> > dist(n, vector<int>(n, inf));
    vector<vector<int> > from(n), to(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
    }

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                if (dist[i][to] == inf) {
                    dist[i][to] = dist[i][v] + 1;
                    q.push(to);
                }
            }
        }
        for (int j = 0; j < 4; ++j) {
            int best = -1;
            for (int k = 0; k < n; ++k) {
                if (k == i || dist[i][k] == inf) {
                    continue;
                }
                bool used = false;
                for (int x : from[i]) {
                    if (x == k) {
                        used = true;
                        break;
                    }
                }
                if (used) {
                    continue;
                }
                if (best == -1 || dist[i][best] < dist[i][k]) {
                    best = k;
                }
            }
            if (best != -1) {
                from[i].pb(best);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            int best = -1;
            for (int k = 0; k < n; ++k) {
                if (k == i || dist[k][i] == inf) {
                    continue;
                }
                bool used = false;
                for (int x : to[i]) {
                    if (x == k) {
                        used = true;
                        break;
                    }
                }
                if (used) {
                    continue;
                }
                if (best == -1 || dist[best][i] < dist[k][i]) {
                    best = k;
                }
            }
            if (best != -1) {
                to[i].pb(best);
            }
        }
    }

    int ans = 0;
    cover c;

    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            if (j == k || dist[j][k] == inf) {
                continue;
            }
            for (int i : to[j]) {
                if (i == k) {
                    continue;
                }
                for (int l : from[k]) {
                    if (l == i || l == j) {
                        continue;
                    }
                    int curr = dist[i][j] + dist[j][k] + dist[k][l];
                    if (curr > ans) {
                        ans = curr;
                        c = {i, j, k, l};
                    }
                }
            }
        }
    }

    //cout << ans << endl;
    cout << c.a + 1 << " " << c.b + 1 << " " << c.c + 1 << " " << c.d + 1 << endl;

}