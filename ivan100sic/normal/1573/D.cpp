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
        vector<int> a(n), b;
        int z = 0;
        for (int& x : a) cin >> x, z += x;
        if (z % 2) {
            cout << "NO\n";
            continue;
        }

        auto go = [&](int l) {
            int x = a[l] ^ a[l+1] ^ a[l+2];
            a[l] = a[l+1] = a[l+2] = x;
            b.push_back(l+1);
        };

        // tight
        auto solve_two_even = [&](int u, int v) {
            for (int i=u; i<=v-4; i+=2) go(i);
            for (int i=v-2; i>=u; i-=2) go(i);
        };

        auto solve_two_odd_left = [&](int u, int v) {
            for (int i=u; i<=v-3; i+=2) go(i);
            for (int i=u-1; i<=v-2; i+=2) go(i);
        };

        auto solve_two_odd_right = [&](int u, int v) {
            for (int i=v; i>=u+3; i-=2) go(i-2);
            for (int i=v+1; i>=u+2; i-=2) go(i-2);
        };

        auto solve_fwd = [&](int l, int r) {
            vector<int> q;
            for (int i=l; i<=r; i++) {
                if (a[i]) {
                    q.push_back(i);
                }
            }

            for (int i=0; i<(int)q.size(); i+=2) {
                int u = q[i], v = q[i+1];
                if ((v-u) % 2 == 0) {
                    solve_two_even(u, v);
                } else {
                    solve_two_odd_left(u, v);
                }
            }
        };

        auto solve_bck = [&](int l, int r) {
            vector<int> q;
            for (int i=l; i<=r; i++) {
                if (a[i]) {
                    q.push_back(i);
                }
            }

            for (int i=q.size()-1; i>=0; i-=2) {
                int u = q[i-1], v = q[i];
                if ((v-u) % 2 == 0) {
                    solve_two_even(u, v);
                } else {
                    solve_two_odd_right(u, v);
                }
            }
        };

        if (a[0] && a[n-1]) {
            int zero = -1, zl = 0;
            for (int i=0; i<n; i++) {
                zl += a[i];
                if (a[i] == 0 && zl % 2 == 0) {
                    zero = i;
                    break;
                }
            }

            if (zero == -1) {
                // one last chance
                vector<int> q;
                for (int i=0; i<n; i++) if (a[i]) q.push_back(i);
                for (int j=0; j<(int)q.size()-1; j+=2) {
                    if ((q[j+1] - q[j]) % 2 == 0) {
                        solve_two_even(q[j], q[j+1]);
                        zero = q[j];
                        break;
                    }
                }

                if (zero == -1) {
                    cout << "NO\n";
                    continue;
                }
            }

            solve_bck(0, zero);
            solve_fwd(zero, n-1);
        } else if (a[0] == 0) {
            solve_fwd(0, n-1);
        } else if (a[n-1] == 0) {
            solve_bck(0, n-1);
        }

        cout << "YES\n" << b.size() << '\n';
        for (int x : b) cout << x << ' ';
        cout << "\n";
    }
}

// 10011001