#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> component;

int diameter;

struct S {
    int largest_down1;
    int idx1;
    int largest_down2;
    int idx2;
    int mdist;
};

vector<S> data;

void max_dist(int v, int p, int c) {
    component[v] = c;

    for (int u : adj[v]) {
        if (u != p) {
            max_dist(u, v, c);

            if (data[u].largest_down1 + 1 > data[v].largest_down1) {
                data[v].largest_down2 = data[v].largest_down1;
                data[v].idx2 = data[v].idx1;
                data[v].largest_down1 = data[u].largest_down1 + 1;
                data[v].idx1 = u;
            } else if (data[u].largest_down1 + 1 > data[v].largest_down2) {
                data[v].largest_down2 = data[u].largest_down1 + 1;
                data[v].idx2 = u;
            }
        }
    }

    diameter = max(diameter, data[v].largest_down1 + data[v].largest_down2);
}

void top_down(int v, int p, int down) {
    data[v].mdist = max(down, data[v].largest_down1);

    for (int u : adj[v]) {
        if (u != p) {
            int l = down + 1;
            if (data[v].idx1 != u)
                l = max(l, data[v].largest_down1 + 1);
            if (data[v].idx2 != u)
                l = max(l, data[v].largest_down2 + 1);
            top_down(u, v, l);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, q;
    cin >> n >> m >> q;

    adj.resize(n);
    data.assign(n, {0, -1, 0, -1, 0});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> diameters(n + 1);
    component.assign(n, -1);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (component[i] == -1) {
            diameter = 0;
            max_dist(i, -1, c);
            diameters[c] = diameter;
            top_down(i, -1, 0);
            c++;
        }
    }

    vector<vector<int>> dists(c), psums(c);
    for (int i = 0; i < n; i++) {
        dists[component[i]].push_back(data[i].mdist);
    }
    for (int i = 0; i < c; i++) 
        sort(dists[i].begin(), dists[i].end());

    for (int i = 0; i < c; i++) {
        psums[i].resize(dists[i].size() + 1);
        psums[i][0] = 0;
        for (int j = 0; j < dists[i].size(); j++)
            psums[i][j + 1] += psums[i][j] + dists[i][j];
    }

    map<pair<int, int>, double> memo;
    for (int qidx = 0; qidx < q; qidx++) {
        int a, b;
        cin >> a >> b;
        a = component[a - 1];
        b = component[b - 1];
        if (dists[a].size() > dists[b].size())
            swap(a, b);

        if (a == b) {
            cout << -1 << '\n';
            continue;
        } 

        auto p = make_pair(a, b);
        if (memo.count(p)) {
            cout << memo[p] << '\n';
            continue;
        }

        auto& v1 = dists[a];
        auto& v2 = dists[b];
        int x = max(diameters[a], diameters[b]);

        double result = 0;
        int i2 = v2.size();
        for (int i1 = 0; i1 < v1.size(); i1++) {
            auto it = lower_bound(v2.begin(), v2.begin() + i2, x - v1[i1] - 1);
            i2 = it - v2.begin();

            result += (double)i2 * x;
            result += psums[b].back() - psums[b][i2];
            result += (v2.size() - i2) * (double)(v1[i1] + 1);
        }
        result /= v1.size();
        result /= v2.size();

        cout << result << '\n';
        memo[p] = result;
    }
}