#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    long long total_sum = 0;
    vector<int> diffs;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        total_sum += a;
        diffs.push_back(a - b);
    }
    sort(diffs.begin(), diffs.end());
    int cnt = 0;
    while (total_sum > m && !diffs.empty()) {
        total_sum -= diffs.back();
        diffs.pop_back();
        cnt++;
    }
    if (total_sum <= m)
        cout << cnt << '\n';
    else
        cout << -1 << '\n';
}