#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;

    vector<int> cnt(k);
    for (auto x : v)
        cnt[x % k]++;

    int total = 0;
    for (int i = 0; i < k; i++) {
        if (i == 0) {
            total += cnt[i] / 2;
        } else if (i + i == k) {
            total += cnt[i] / 2;
        } else if (i < k - i) {
            total += min(cnt[i], cnt[k-i]);
        }
    }
    cout << total * 2 << '\n';
    
}