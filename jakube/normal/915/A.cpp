#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int best = std::numeric_limits<int>::max();
    for (auto x : v) {
        if (k % x == 0)
            best = min(best, k / x);
    }
    cout << best << '\n';
}