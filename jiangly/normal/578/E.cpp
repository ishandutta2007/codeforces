#include <bits/stdc++.h>
using namespace std;
pair<int, vector<int>> work(string s) {
    int n = (int)s.length();
    set<int> pos[2];
    for (int i = 0; i < n; ++i)
        pos[s[i] == 'R'].insert(i);
    int ans = -1;
    vector<vector<int>> f[4];
    while (!pos[0].empty() || !pos[1].empty()) {
        ++ans;
        int c = pos[0].empty() || !pos[1].empty() && *pos[0].begin() > *pos[1].begin();
        int p = *pos[c].begin();
        vector<int> steps;
        while (true) {
            pos[c].erase(p);
            steps.push_back(p);
            c ^= 1;
            auto i = pos[c].upper_bound(p);
            if (i == pos[c].end())
                break;
            p = *i;
        }
        f[(s[steps.front()] == 'L') << 1 | (s[steps.back()] == 'L')].push_back(move(steps));
    }
    vector<int> steps;
    if (f[0].size() < f[3].size()) {
        swap(f[0], f[3]);
        swap(f[1], f[2]);
    }
    for (auto &i : f[1])
        steps.insert(steps.end(), i.begin(), i.end());
    for (int i = 0; i < (int)f[3].size(); ++i) {
        steps.insert(steps.end(), f[0][i].begin(), f[0][i].end());
        steps.insert(steps.end(), f[3][i].begin(), f[3][i].end());
    }
    steps.insert(steps.end(), f[0].back().begin(), f[0].back().end());
    for (auto &i : f[2])
        steps.insert(steps.end(), i.begin(), i.end());
    return {ans, steps};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> s;
    n = (int)s.length();
    pair<int, vector<int>> ans;
    if (n % 2 == 0) {
        s.pop_back();
        ans = work(s);
        ans.second.push_back(n - 1);
    } else {
        ans = work(s);
    }
    cout << ans.first << "\n";
    for (int i = 0; i < n; ++i)
        cout << ans.second[i] + 1 << " \n"[i == n - 1];
    return 0;
}