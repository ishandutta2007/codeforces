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
        vector<int> a(n+1), b(n+1);
        vector<vector<int>> e(n+1);
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            e[a[i]].push_back(i);
        }

        int z = 0;

        set<int> unused;
        for (int x=1; x<=n; x++) {
            if (e[x].empty()) {
                unused.insert(x);
            } else {
                z++;
            }
        }

        b = a;

        for (int x=1; x<=n; x++) {
            // ima ih vise sa ovom vrednoscu?
            int sz = e[x].size();
            if (sz > 1) {
                set<int> ins;
                for (int r=0; r<sz-1; r++) {
                    ins.insert(*unused.begin());
                    unused.erase(unused.begin());
                }

                for (int i : e[x]) {
                    // probaj prvog
                    if (ins.size() && *ins.begin() != i) {
                        b[i] = *ins.begin();
                        ins.erase(ins.begin());
                    } else if (ins.size() >= 2 && *next(ins.begin()) != i) {
                        int x = *next(ins.begin());
                        b[i] = x;
                        ins.erase(x);
                    } else {
                        // ili je ostao 1 i nemam gde da ga stavim (stavicu ga u sledeco)
                        // ili nema nista :)
                    }
                }
            }
        }

        cout << z << '\n';
        for (int i=1; i<=n; i++) {
            cout << b[i] << " \n"[i == n];
        }
    }
}