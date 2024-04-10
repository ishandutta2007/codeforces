#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 2E5, MAX_C = 2E5;
int n, k;
int l[MAX_N], r[MAX_N];
vector<int> s[MAX_C + 1], t[MAX_C + 1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        --l[i];
        s[l[i]].push_back(i);
        t[r[i]].push_back(i);
    }
    set<pair<int, int>> segs;
    vector<int> rem;
    for (int i = 0; i <= MAX_C; ++i) {
        for (int x : t[i])
            segs.erase({r[x], x});
        for (int x : s[i]) {
            segs.emplace(r[x], x);
            if (segs.size() > k) {
                auto j = --segs.end();
                rem.push_back(j->second);
                segs.erase(j);
            }
        }
    }
    cout << rem.size() << "\n";
    for (int i = 0; i < rem.size(); ++i)
        cout << rem[i] + 1 << " \n"[i == rem.size() - 1];
    return 0;
}