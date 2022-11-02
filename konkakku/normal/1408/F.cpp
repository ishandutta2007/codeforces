#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
vector<pair<int, int>> ans;
vector<vector<int>> ve;

void solve(int l, int r) {
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    solve(l, m);
    solve(m + 1, r);
    for (int i = l; i <= m; i++) {
        ans.push_back({i, r + l - i});
    }
}

void merge(vector<int>& le, vector<int>& ri) {
    for (int i = 0; i < ri.size(); i++) {
        ans.push_back({le[i], ri[i]});
    }
    while (!ri.empty()) {
        le.push_back(ri.back());
        ri.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int pt = 1;
    for (int i = 20; i >= 0; i--) {
        if (n >> i & 1) {
            int tmp = (1 << i);
            solve(pt, pt + tmp - 1);
            vector<int> cur;
            for (int j = pt; j < pt + tmp; j++) {
                cur.push_back(j);
            }
            ve.push_back(cur);
            pt += tmp;
        }
    }
    vector<int> lar = ve[0]; ve.erase(ve.begin());
    while (ve.size() >= 2) {
        auto le = ve.back(); ve.pop_back();
        auto ri = ve.back(); ve.pop_back();
        while (le.size() < ri.size()) {
            vector<int> cur;
            while (cur.size() < le.size()) {
                cur.push_back(lar.back());
                lar.pop_back();
            }
            merge(le, cur);
        }
        merge(le, ri);
        ve.push_back(le);
    }
    cout << ans.size() << '\n';
    for (auto [l, r] : ans) {
        cout << l << " " << r << '\n';
    }
}