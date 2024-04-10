// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[1000005];
int f[1 << 20];
vector<int> dirty;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    memset(f, 255, sizeof(f));

    int sol = 0;
    for (int i=0; i<20; i++) {
        bool inside = false;
        int z = 0;
        for (int j=0; j<n; j++) {
            if (a[j] & 1) {
                if (inside) {
                    z ^= a[j];
                    dirty.push_back(z);
                    if (f[z] != -1) {
                        sol = max(sol, j + 1 - f[z]);
                    } else {
                        f[z] = j + 1;
                    }
                } else {
                    for (int x : dirty) f[x] = -1;
                    dirty = {};
                    f[0] = j;
                    z = a[j];
                    f[z] = j+1;
                    dirty.push_back(0);
                    dirty.push_back(z);
                    inside = true;
                }
            } else {
                inside = false;
            }
        }

        for (int j=0; j<n; j++) {
            a[j] >>= 1;
        }
    }

    cout << sol << '\n';
}