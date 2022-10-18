#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, l;
    cin >> w >> l;
    vector<int> v(w-1);
    for (int i = 0; i < w-1; i++) {
        cin >> v[i];
    }
    vector<long long> psum(v.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < v.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + v[psum_idx];
    }

    long long best = std::numeric_limits<long long>::max();
    for (int i = 0; i + l <= w - 1; i++) {
        best = min(best, psum[i + l] - psum[i]);
    }
    cout << best << '\n';
}