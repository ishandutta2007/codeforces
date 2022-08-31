#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p;
    cin >> n >> p;
    vector<LL> t(n);
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = i;
    sort(a.begin(), a.end(), [&](int i, int j) {return t[i] < t[j] || t[i] == t[j] && i < j;});
    vector<LL> ans(n);
    LL lst = 0;
    set<int> can, q;
    deque<int> que;
    for (int i = 0; i < n; ++i) {
        while (!que.empty() && ans[que.front()] < t[a[i]]) {
            q.erase(que.front());
            que.pop_front();
            if (!can.empty() && (que.empty() || *can.begin() < *q.begin())) {
                int x = *can.begin();
                can.erase(x);
                ans[x] = max(lst, LL(t[x])) + p;
                lst = ans[x];
                que.push_back(x);
                q.insert(x);
            }
        }
        if (!can.empty() && (que.empty() || *can.begin() < *q.begin())) {
            int x = *can.begin();
            can.erase(x);
            ans[x] = max(lst, LL(t[x])) + p;
            lst = ans[x];
            que.push_back(x);
            q.insert(x);
        }
        can.insert(a[i]);
    }
    while (!can.empty()) {
        int x = *can.begin();
        can.erase(x);
        ans[x] = max(lst, LL(t[x])) + p;
        lst = ans[x];
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
    return 0;
}