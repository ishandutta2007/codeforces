#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
void solve(int case_id) {
    int n, k;
    cin >> n >> k;
    deque<int> que;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        if (!s.count(id)) {
            if (que.size() == k) {
                s.erase(que.front());
                que.pop_front();
            }
            que.push_back(id);
            s.insert(id);
        }
    }
    cout << que.size() << "\n";
    reverse(que.begin(), que.end());
    for (int x : que)
        cout << x << " \n"[x == que.back()];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i)
        solve(i);
    return 0;
}