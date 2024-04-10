// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, k;
int c[505], z, l;
int d[505], p[505], pi[505];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k;

    memset(d, 255, sizeof(d));
    d[0] = 0;

    queue<int> q;
    q.push(0);
    while (q.size()) {
        int x = q.front(); q.pop();
        for (int i=0; i<=k; i++) {
            if (i > x) continue;
            if (k-i > n-x) continue;
            int y = x - i + (k - i);
            if (d[y] == -1) {
                d[y] = d[x] + 1;
                p[y] = x;
                pi[y] = i;
                q.push(y);
            }
        }
    }

    if (d[n] == -1) {
        cout << "-1\n";
        return 0;
    }

    for (int x=n; x; x=p[x]) {
        int c1 = pi[x];
        int c0 = k - c1;
        cout << "?";
        for (int i=0; i<n; i++) {
            int y = 0;
            if (c1 && c[i] == 1) {
                y = 1;
                c1--;
            } else if (c0 && c[i] == 0) {
                y = 1;
                c0--;
            }
            if (y) {
                cout << ' ' << i+1;
                c[i] ^= 1;
            }
        }
        cout << "\n" << flush;
        int r;
        cin >> r;
        z ^= r;
    }

    cout << "! " << z << '\n' << flush;
}