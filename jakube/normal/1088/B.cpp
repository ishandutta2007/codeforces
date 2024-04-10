#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.resize(it - v.begin());
    int last = 0;
    for (int i = 0; i < k; i++) {
        if (i < v.size()) {
            cout << v[i] - last << '\n';
            last = v[i];
        } else
            cout << 0 << '\n';
    }
}