#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<long long> psum(v.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < v.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + v[psum_idx];
    }

    int best = 0;
    for (int i = 1; i < n; i++) {
        best = max(best, (int)((psum[i] % p) + (psum[n] - psum[i]) % p));
    }
    cout << best << endl;
}