#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].second >> p[i].first;
    sort(p.begin(), p.end(), greater<pair<int, int>>());
    priority_queue<int, vector<int>, greater<int>> h;
    LL sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        h.push(p[i].second);
        sum += p[i].second;
        if ((int)h.size() > k) {
            sum -= h.top();
            h.pop();
        }
        ans = max(ans, sum * p[i].first);
    }
    cout << ans << endl;
    return 0;
}