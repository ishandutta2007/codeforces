#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> psum(v.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < v.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + v[psum_idx];
    }
    auto sum = [&psum](int x, int y) {
        return psum[y+1] - psum[x];
    };

    for (int i = 0; i <= n; i++) {
        if ((sum(i, n-1) + 5*i) * 2 >= 9 * n) {
            cout << i << '\n';
            break;
        }
    }
}