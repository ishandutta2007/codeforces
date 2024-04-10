#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int l, r, idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Segment> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].idx = i + 1;
    }
    sort(v.begin(), v.end(), [](auto p, auto q) {
        if (p.l == q.l)
            return p.r > q.r;
        return p.l < q.l;
    });

    set<pair<int, int>> ms;
    for (auto p : v) {
        ms.insert({p.r, p.idx});
    }

    for (auto p : v) {
        ms.erase(ms.find({p.r, p.idx}));
        if (!ms.empty() && ms.begin()->first <= p.r) {
            cout << ms.begin()->second << " " << p.idx << '\n';
            return 0;
        }
    }
    cout << -1 << " " << -1 << '\n';
    
}