#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> V(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    vector<long long> T(n);
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }
    vector<long long> psum(T.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < T.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + T[psum_idx];
    }

    vector<int> full(n + 1, 0);
    vector<long long> partly(n, 0);
    for (int i = 0; i < n; i++) {
        long long cur = V[i] + psum[i];
        int idx = upper_bound(psum.begin(), psum.end(), cur) - psum.begin();
        full[idx - 1]--;
        full[i]++;
        if (idx - 1 < n)
            partly[idx - 1] += cur - psum[idx - 1];
    }
    for (int i = 0; i < n; i++) 
        full[i+1] += full[i];

    for (int i = 0; i < n; i++) {
        cout << T[i] * full[i] + partly[i] << " ";
    }
    cout << endl;
}