#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto x = find(a.begin(), a.end(), -1);
    fill(a.begin(), x, 0);
    a.erase(x);
    priority_queue<int, vector<int>, greater<int>> h;
    reverse(a.begin(), a.end());
    int s = 0;
    long long ans = 0;
    for (int l = n / 2; l > 0; l /= 2) {
        h.push(a[s]);
        ans += h.top();
        h.pop();
        for (int i = s + 1; i < s + l; ++i) h.push(a[i]);
        s += l;
    }
    cout << ans << endl;
    return 0;
}