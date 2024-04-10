#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> next_not_one(n, -1);
    int last = n;
    for (int i = n-1; i >= 0; i--) {
        next_not_one[i] = last;
        if (v[i] != 1)
            last = i;
    }

    vector<long long> psum(v.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < v.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + v[psum_idx];
    }
    auto sum = [&psum](int x, int y) {
        return psum[y+1] - psum[x];
    };

    long long cnt = 0;
    long long m = 3e18 + 5;
    for (int i = 0; i < n; i++) {
        long long p = v[i];
        int j = i;
        while (j < n && p < m) {
            long long s = sum(i, j);
            if (m / k > s && p == k * s)
                cnt++;

            int ones = next_not_one[j] - j - 1;
            if (p % k == 0 && p / k - s >= 1 && p / k - s <= ones)
                cnt++;

            j = next_not_one[j];
            if (j == n)
                break;
            if (p > m / v[j])
                break;
            p *= v[j];
        }
    }
    cout << cnt << '\n';
    
}