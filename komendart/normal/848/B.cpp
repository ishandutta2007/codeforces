#include <bits/stdc++.h>

using namespace std;

struct Dancer {
    int g, pos, ind;
};

int n, w, h;
map<int, vector<Dancer> > cl;
vector<Dancer> a;
vector< pair<int, int> > ans;

void process(vector<Dancer> dancers) {
    vector< pair<int, int> > x;
    vector< pair<int, int> > y;
    for (auto it: dancers) {
        if (it.g == 1) {
            x.push_back({it.pos, it.ind});
        } else {
            y.push_back({it.pos, it.ind});
        }
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    deque<int> q;
    for (auto it: x) {
        q.push_back(it.second);
    }
    for (auto it: y) {
        if (q.empty()) {
            ans[it.second] = {w, a[it.second].pos};
            continue;
        }
        q.push_front(it.second);
        int tmp = q.back(); q.pop_back();
        ans[tmp] = {w, a[it.second].pos};
    }
    for (int i = 0; i < x.size(); ++i) {
        ans[q[i]] = {x[i].first, h};
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> w >> h;
    ans.resize(n);
    for (int i = 0; i < n; ++i) {
        int g, p, t;
        cin >> g >> p >> t;
        a.push_back(Dancer{g, p, i});
        cl[p - t].push_back(Dancer{g, p, i});
    }
    for (auto p: cl) {
        process(p.second);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}