#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> psum(a.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < a.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + a[psum_idx];
    }
    auto sum = [&psum](int x, int y) {
        return psum[y+1] - psum[x];
    };

    double m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + k - 1; j < n; j++) {
            m = max(m, sum(i, j) / (double)(j - i + 1));
        }
    }
    std::cout << std::fixed << std::setprecision(15);
    cout << m << '\n';
}