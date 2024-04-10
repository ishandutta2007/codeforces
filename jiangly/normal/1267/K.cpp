#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long k;
    cin >> k;
    int t = 2;
    vector<int> key;
    while (k > 0) {
        key.push_back(k % t);
        k /= t;
        ++t;
    }
    vector<int> cnt(key.size() + 1);
    auto count = [&]() {
        auto sum = cnt;
        for (int i = 1; i < sum.size(); ++i)
            sum[i] += sum[i - 1];
        long long ans = 1;
        for (int i = 0; i < key.size(); ++i)
            ans *= sum[i + 1] - i;
        for (int i = 0; i < cnt.size(); ++i)
            for (int j = 1; j <= cnt[i]; ++j)
                ans /= j;
        return ans;
    };
    for (int i : key)
        ++cnt[i];
    long long ans = count();
    if (cnt[0] > 0) {
        --cnt[0];
        key.pop_back();
        ans -= count();
    }
    cout << ans - 1 << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}