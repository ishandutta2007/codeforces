#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];

    vector<long long> cnt(1e7 + 1, 0);
    for (int s : v) {
        cnt[s]++;
    }

    vector<long long> tt(1e7 + 1, 0);
    long long total = 0;
    for (int i = cnt.size() - 1; i > 0; i--) {
        total += cnt[i];
        total -= tt[i];

        if (total >= k) {
            cout << i << endl;
            return 0;
        }

        cnt[i/2] += cnt[i];
        cnt[(i+1)/2] += cnt[i];
        tt[(i+1)/2] += cnt[i];
    }

    cout << -1 << endl;
    return 0;
}