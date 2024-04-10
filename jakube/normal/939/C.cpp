#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(2*n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    int s, f;
    cin >> s >> f;
    
    vector<int> psum(a.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < a.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + a[psum_idx];
    }

    int best = 0;
    int best_sum = 0;
    
    for (int i = 1; i <= n; i++) {
        int sum = psum[n - i + f] - psum[n - i + s];
        if (sum > best_sum) {
            best_sum = sum;
            best = i;
        }
    }

    cout << best << endl;
}