#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int w, b, number;
};

bool cmp(const Edge &a, const Edge &b) {
    return make_pair(a.w, -a.b) < make_pair(b.w, -b.b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<Edge> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].w >> a[i].b;
        a[i].number = i;
    }
    sort(a.begin(), a.end(), cmp);

    vector< pair<int, int> > result(m);
    vector< pair<int, int> > edges; edges.reserve(m);
    int cnt = 0;
    int last = 0;
    for (auto edge: a) {
        if (edge.b) {
            last++;
            result[edge.number] = {0, last};
            for (int i = 1; i < last && cnt < m; i++) {
                edges.push_back({i, last});
                cnt++;
            }
        } else {
            if (edges.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            result[edge.number] = edges.back();
            edges.pop_back();
        }
    }

    for (auto i: result) {
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
}