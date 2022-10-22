#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> g(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x *= -1;
            x += i;
            g[i] = x;
        }
        vector<int> used(n), p(n), ans;
        int t = 0;
        for (int s = 0; s < n; s++) {
            if (used[s]) {
                continue;
            }
            t++;
            int v = s;
            while (1) {
                used[v] = t;
                int u = g[v];
                if (!used[u]) {
                    p[u] = v;
                    v = u;
                    continue;
                }
                if (used[u] != t) {
                    break;
                }
                while (1) {
                    ans.push_back(v);
                    if (v == u) {
                        break;
                    }
                    v = p[v];
                }
                break;
            }
            if ((int) ans.size()) {
                break;
            }
        }
        cout << (int) ans.size() << '\n';
        for (auto i : ans) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    }
}