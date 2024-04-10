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
        int n;
        cin >> n;
        vector<vector<int>> e(n);
        for (int i : ra(1, n)) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        vector<int> d(n, -1);
        queue<int> q;
        q.push(0);
        d[0] = 0;
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int y : e[x]) {
                if (d[y] == -1) {
                    d[y] = d[x] ^ 1;
                    q.push(y);
                }
            }
        }

        vector<int> c[2], p(n);
        set<int> unusd;
        for (int i : ra(0, n)) {
            c[d[i]].push_back(i);
            unusd.insert(i+1);
        }
        
        int cl = c[1].size() < c[0].size();
        int rem = c[cl].size(), did = 0;

        for (int w=1; rem>0; w*=2) {
            if (w & rem) {
                for (int i : ra(did, did+w)) {
                    int k = i - did + w;
                    p[c[cl][i]] = k;
                    unusd.erase(k);
                }
                did += w;
                rem -= w;
            }
        }

        for (int x : c[cl^1]) {
            p[x] = *unusd.begin();
            unusd.erase(unusd.begin());
        }

        for (int x : p) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}