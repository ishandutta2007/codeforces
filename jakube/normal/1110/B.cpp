#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n);
    for (auto& x : b)
        cin >> x;

    int ans = b[n-1] - b[0] + 1;
    vector<int> diffs(n-1);
    for (int i = 0; i < n - 1; i++) {
        diffs[i] = b[i+1] - b[i] - 1;
    }
    sort(diffs.begin(), diffs.end());
    reverse(diffs.begin(), diffs.end());
    k--;
    for (int i = 0; i < k; i++) {
        ans -= diffs[i];
    }
    cout << ans << '\n';
}