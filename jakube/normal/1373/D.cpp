#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    
    long long sum = 0;
    for (int i = 0; i < n; i+=2) {
        sum += v[i];
    }

    vector<long long> w(2, 0);
    for (int offset = 0; offset < 2; offset++) {
        long long cur_sum = 0;
        long long best_sum = 0;
        for (int i = offset; i + 1 < n; i+=2) {
            long long tmp = -v[i] + v[i+1];
            if (offset)
                tmp = -tmp;
            cur_sum = max(0LL, cur_sum + tmp);
            best_sum = max(cur_sum, best_sum);
        }
        w[offset] = best_sum;
    }
    cout << sum + *max_element(w.begin(), w.end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}