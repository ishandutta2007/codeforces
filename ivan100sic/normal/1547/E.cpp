// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> d(n, 2e9);
        vector<int> x(k), t(k);
        set<pair<int, int>> pq;
        for (int i=0; i<k; i++) cin >> x[i], x[i]--;
        for (int i=0; i<k; i++) {
            cin >> t[i];
            d[x[i]] = t[i];
            pq.insert({t[i], x[i]});
        }
        while (pq.size()) {
            auto [dx, x] = *pq.begin(); pq.erase(pq.begin());
            for (int y : {x-1, x+1}) {
                if (y >= 0 && y < n) {
                    if (d[y] > dx + 1) {
                        pq.erase({d[y], y});
                        d[y] = dx + 1;
                        pq.insert({d[y], y});
                    }
                }
            }
        }

        for (int i=0; i<n; i++) {
            cout << d[i] << " \n"[i == n-1];
        }
    }
}