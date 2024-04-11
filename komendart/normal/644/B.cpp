#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, b;
    cin >> n >> b;

    vector<int> answer(n, -1);
    deque< pair<int, int> > q;
    for (int i = 0; i < n; i++) {
        int x, d;
        cin >> x >> d;
        while (!q.empty() && q.front().second <= x) {
            answer[q.front().first] = q.front().second;
            q.pop_front();
        }
        if (q.empty()) q.push_back({i, x + d});
        else if (q.size() <= b) q.push_back({i, q.back().second + d});
    }
    while (!q.empty()) {
        answer[q.front().first] = q.front().second;
        q.pop_front();
    }

    for (auto i: answer) cout << i << ' ';
}