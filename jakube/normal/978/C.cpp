#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> psum(a.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < a.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + a[psum_idx];
    }

    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        x--;
        int dorm = upper_bound(psum.begin(), psum.end(), x) - psum.begin();
        dorm--;
        cout << dorm + 1 << " " << x - psum[dorm] + 1 << '\n';
        
    }
}