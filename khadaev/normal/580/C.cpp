#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, x, y, cats[100000], ans[100000], curr[100000];
    vector<int> nears[100000];
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> cats[i];
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        nears[x - 1].push_back(y - 1);
        nears[y - 1].push_back(x - 1);
        };
    set<int> used, active, new_active;
    active.insert(0);
    ans[0] = cats[0];
    curr[0] = cats[0];
    while (!active.empty()) {
        //cerr << active.size();
        new_active.clear();
        for (auto i = active.begin(); i != active.end(); ++i) {
            for (auto j = nears[*i].begin(); j != nears[*i].end(); ++j) {
                if (used.count(*j) > 0 || active.count(*j) > 0) continue;
                new_active.insert(*j);
                if (cats[*j] == 1) curr[*j] = curr[*i] + 1;
                else curr[*j] = 0;
                ans[*j] = max(ans[*i], curr[*j]);
                };
            used.insert(*i);
            };
        active = new_active;
        };
    long long rez = 0;
    for (int i = 0; i < n; ++i)
        if (i > 0 && nears[i].size() == 1 && ans[i] <= m) /*cerr << i << " " << ans[i] << "\n";*/++rez;
    cout << rez;
    //for (int i = 0; i < n; ++i) cerr << i << " " << ans[i] << "!\n";
};