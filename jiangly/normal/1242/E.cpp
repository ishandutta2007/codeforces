#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int f;
    cin >> f;
    vector<pair<int, int>> a(f);
    for (int i = 0; i < f; ++i) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    int n = 0;
    deque<int> q;
    vector<vector<int>> v(f);
    for (int i = 0; i < a[0].first; ++i) {
        q.push_back(n);
        v[a[0].second].push_back(n);
        ++n;
    }
    for (int i = 1; i < f; ++i) {
        int e, k;
        tie(e, k) = a[i];
        int p = min(e - 1, ((int)q.size() + e - (i == f - 1 ? 3 : a[i + 1].first)) / 2);
        for (int j = 0; j < p - 1; ++j) {
            v[k].push_back(q.back());
            q.pop_back();
        }
        v[k].push_back(q.back());
        for (int j = p; j < e - 1; ++j) {
            v[k].push_back(n);
            q.push_back(n);
            ++n;
        }
        v[k].push_back(q.front());
        q.push_back(q.front());
        q.pop_front();
    }
    cout << n << "\n";
    for (int i = 0; i < f; ++i)
        for (int j : v[i])
            cout << j + 1 << " \n"[j == v[i].back()];
    return 0;
}