#include<bits/stdc++.h>

using namespace std;

struct node {
  long long dist[2][2];
  int l = - 1, r = -1;
  node() {};
};

const int N = 1e5 + 22;
node t[4 * N];
pair<int, int> d[N][2];

int dist(pair<int, int> x, pair<int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

node merge(node a, node b) {
    if (a.l == -1) {
        return b;
    }
    if (b.l == -1) {
        return a;
    }
    node res;
    res.l = a.l, res.r = b.r;
    for (int i = 0; i < 2; i++) {
        for (int j2 = 0; j2 < 2; j2++) {
            res.dist[i][j2] = (long long) 1e18;
            for (int i2 = 0; i2 < 2; i2++) {
                for (int j = 0; j < 2; j++) {
                    long long result = a.dist[i][j] + b.dist[i2][j2] + 1;
                    auto x = d[a.r][j];
                    if (j == 0) {
                        x.second++;
                    } else {
                        x.first++;
                    }
                    result += dist(x, d[b.l][i2]);
                    res.dist[i][j2] = min(res.dist[i][j2], result);
                }
            }
        }
    }
    return res;
}

void build(int v, int l, int r) {
    t[v].l = l, t[v].r = r - 1;
    if (l + 1 == r) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                t[v].dist[i][j] = dist(d[l][i], d[l][j]);
            }
        }
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

node get(int v, int l, int r, int l1, int r1) {
    if (l1 >= r || l >= r1) {
        return node();
    }
    if (l1 <= l && r <= r1) {
        return t[v];
    }
    int m = (l + r) / 2;
    return merge(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m, r, l1, r1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i + 1 < n; i++) {
        cin >> d[i][0].first >> d[i][0].second >> d[i][1].first >> d[i][1].second;
        swap(d[i][0].first, d[i][0].second);
        swap(d[i][1].first, d[i][1].second);
    }
    build(0, 0, n - 1);
    int q;
    cin >> q;
    while (q--) {
        int x, y, x2, y2;
        cin >> x >> y >> x2 >> y2;
        swap(x, y), swap(x2, y2);
        int level = max(x, y) - 1, level2 = max(x2, y2) - 1;
        if (level == level2) {
            cout << abs(x - x2) + abs(y - y2) << '\n';
            continue;
        }
        if (level > level2) {
            swap(level, level2);
            swap(x, x2);
            swap(y, y2);
        }
        //cout << level << " " << level2 - 1 << endl;
        node res = get(0, 0, n - 1, level, level2);
        /*for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) cout << res.dist[i][j] << " ";
            cout << endl;
        } cout << "F" << res.l << " " << res.r << endl;*/
        long long ans = (long long) 1e18;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                long long result = res.dist[i][j] + dist({x, y}, d[level][i]);
                auto V = d[level2 - 1][j];
                if (j == 0) {
                    V.second++;
                } else {
                    V.first++;
                }
                //cout << i << " " << j << " " << result << endl;
                result += dist({x2, y2}, V) + 1;
                ans = min(ans, result);
            }
        }
        cout << ans << '\n';
    }
}