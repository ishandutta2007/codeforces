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
    
    auto sum = accumulate(v.begin(), v.end(), 0LL);
    vector<long long> psum(v.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < v.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + v[psum_idx];
    }

    auto ssum = 0LL;

    auto best = ssum;
    for (int i = n-1; i >= 0; i--) {
        ssum += v[i];
        if (ssum * 2 > sum) break;
        if (*lower_bound(psum.begin(), psum.end(), ssum) == ssum)
            best = ssum;
    }
    cout << best << '\n';
}