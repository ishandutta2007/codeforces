// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
vector<pair<int, int>> e[200005];
int v[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) e[i] = {}, v[i] = 0;

        for (int i=0; i<m; i++) {
            int x, y;
            string s;
            cin >> x >> y >> s;
            int b = s[0] == 'i';
            e[x].push_back({y, b});
            e[y].push_back({x, b});
        }

        int sol = 0;
        bool ok = true;

        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                int c[4] = {0, 0};
                queue<int> q;
                q.push(i);
                v[i] = 2;
                c[v[i]]++;
                while (q.size()) {
                    int x = q.front();
                    q.pop();
                    for (auto [y, b] : e[x]) {
                        if (!v[y]) {
                            v[y] = v[x] ^ b;
                            c[v[y]]++;
                            q.push(y);
                        } else if ((v[y] ^ v[x]) != b) {
                            ok = false;
                        }
                    }
                }

                sol += max(c[2], c[3]);
            }
        }

        if (!ok) sol = -1;
        cout << sol << '\n';
    }
}