// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        // Read input        
        int n;
        cin >> n;
        const auto N = ra(0, n);
        vector<int> a(n);
        for (int& x : a) cin >> x, x--;

        // Fill up e-vector
        vector<vector<int>> e(n);
        if (n % 2) e[a[n/2]].push_back(n/2);
        for (int i : N) {
            if (n % 2 && i == n/2) continue;
            e[a[i]].push_back(i);
        }

        // check if valid
        {
            int odd = 0;
            for (int i : N) {
                if (size(e[i]) % 2) {
                    odd++;
                }
            }
            if (odd >= 2 || size(e[a[n/2]]) == 1) {
                cout << "NO\n";
                continue;
            }
        }

        // Recolor
        vector<int> inv(n);
        {
            int col = 0;
            for (unsigned rem : {0, 1}) {
                for (int x : N) {
                    if (size(e[x]) % 2 == rem) {
                        for (int i : e[x]) {
                            a[i] = col;
                            inv[col++] = i;
                        }
                    }
                }
            }
        }

        vector<pair<int, int>> swaps;

        auto swc = [&](int i, int j) {
            swap(a[i], a[j]);
            inv[a[i]] = i;
            inv[a[j]] = j;
        };

        auto sw = [&](int i, int j) {
            swaps.emplace_back(i, j);
            swc(i, j);  
        };

        // Solve
        auto solve_even = [&](span<int> s, auto self) {
            if (s.empty()) return;
            if (size(s) == 2) {
                sw(s[0], s[1]);
                return;
            }

            int il = s[0], ir = s.back();
            if ((a[il] ^ a[ir]) == 1) {
                self(s.subspan(1, size(s) - 2), self);
                int y1 = a[s[1]];
                int y2 = y1 ^ 1;
                int ip = inv[y1];
                int iq = inv[y2];

                sw(il, ip);
                sw(ir, iq);
            } else {
                // iq = brother of ir inside
                int iq = inv[a[ir] ^ 1]; 

                // make solvable
                int xil = a[il];
                int xiq = a[iq];
                swc(il, iq);
                self(s.subspan(1, size(s) - 2), self);
                // undo color swapping
                swc(inv[xil], inv[xiq]);

                // finish
                iq = inv[a[ir] ^ 1]; 

                sw(il, iq);
                sw(il, ir);
            }
        };

        if (n % 2 == 0) {
            vector<int> idx(n);
            iota(begin(idx), end(idx), 0);
            solve_even(idx, solve_even);
        } else {
            vector<int> idx;
            for (int i : ra(0, n)) {
                if (i != n/2) {
                    idx.push_back(i);
                }
            }

            int ic = inv[n-1];
            int jc = n/2;
            int xc = a[ic];
            int yc = a[jc];

            swc(ic, jc);
            solve_even(idx, solve_even);
            ic = inv[xc];
            jc = inv[yc];
            swc(ic, jc);
            sw(ic, jc);
        }

        // Print output based on swaps
        vector<int> output(n);
        iota(begin(output), end(output), 1);
        for (auto [x, y] : swaps) {
            swap(output[x], output[y]);
        }

        cout << "YES\n";
        for (int x : output) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}