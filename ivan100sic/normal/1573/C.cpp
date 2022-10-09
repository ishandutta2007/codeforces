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
        int n;
        cin >> n;
        vector<vector<int>> f(n), b(n);
        vector<int> indeg(n), sol(n, -1);

        for (int i=0; i<n; i++) {
            int k;
            cin >> k;
            for (int j=0; j<k; j++) {
                int x;
                cin >> x;
                x--;
                f[x].push_back(i);
                b[i].push_back(x);
                indeg[i]++;
            }
        }

        queue<int> q;
        for (int i=0; i<n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (q.size()) {
            int x = q.front();
            q.pop();
            int maxlo = -1, maxhi = -1;
            for (int y : b[x]) {
                if (y < x) maxlo = max(maxlo, sol[y]);
                else maxhi = max(maxhi, sol[y]);
            }

            sol[x] = max({1, maxlo, maxhi + 1});
            for (int y : f[x]) {
                if (0 == --indeg[y]) {
                    q.push(y);
                }
            }
        }

        if (count(begin(sol), end(sol), -1)) {
            cout << "-1\n";
        } else {
            cout << *max_element(begin(sol), end(sol)) << '\n';
        }
    }
}