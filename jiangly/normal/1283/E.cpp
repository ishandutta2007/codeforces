#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    sort(x.begin(), x.end());
    int lst = -1, ans = 0;
    for (int i : x) {
        if (lst < i - 1) {
            ++ans;
            lst = i + 1;
        }
    }
    cout << ans << " ";
    lst = -1;
    ans = 0;
    for (int i : x) {
        if (lst != i + 1) {
            ++ans;
            lst = max(lst + 1, i - 1);
        }
    }
    cout << ans << "\n";
    return 0;
}