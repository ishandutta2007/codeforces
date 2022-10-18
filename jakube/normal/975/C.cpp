#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> psum(a.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < a.size(); psum_idx++)
        psum[psum_idx+1] = psum[psum_idx] + a[psum_idx];
    
    long long damage = 0;
    for (int Q = 0; Q < q; Q++) {
        long long k;
        cin >> k;
        int dead = upper_bound(psum.begin(), psum.end(), damage + k) - psum.begin() - 1;
        damage += k;
        if (dead == n) {
            dead = 0;
            damage = 0;
        }
        cout << n - dead << '\n';
    }
}