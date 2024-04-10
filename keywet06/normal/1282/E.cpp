#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

struct triple {
    int first, second, third;
};

vector<triple> g[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        vector<int> deg(n);
        for (int i = 0; i < n - 2; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--, c--;
            g[a].push_back({b, c, i});
            g[b].push_back({a, c, i});
            g[c].push_back({a, b, i});
            deg[a]++, deg[b]++, deg[c]++;
        }
        vector<triple> rofl;
        vector<bool> die(n);
        set<pair<int, int> > q;
        for (int i = 0; i < n; i++) {
            q.insert({deg[i], i});
        }
        vector<int> verts;
        vector<triple> e;
        vector<int> l(n, -1);
        vector<int> r(n, -1);
        vector<int> ans;
        while (!q.empty()) {
            if (q.size() == 3) {
                int v = q.begin()->second;
                for (auto c : g[v]) {
                    if (!die[c.first] && !die[c.second]) {
                        ans.push_back(c.third);
                        break;
                    }
                }
                vector<int> kek;
                for (auto c : q) {
                    kek.push_back(c.second);
                }
                for (int i = 0; i < 3; i++) {
                    l[kek[(i + 1) % 3]] = kek[i];
                    r[kek[i]] = kek[(i + 1) % 3];
                }
                break;
            }
            int v = q.begin()->second;
            q.erase(q.begin());
            die[v] = true;
            verts.push_back(v);
            for (auto c : g[v]) {
                if (!die[c.first] && !die[c.second]) {
                    q.erase({deg[c.first], c.first});
                    q.erase({deg[c.second], c.second});
                    deg[c.first]--;
                    deg[c.second]--;
                    q.insert({deg[c.first], c.first});
                    q.insert({deg[c.second], c.second});
                    l[v] = c.first;
                    r[v] = c.second;
                    ans.push_back(c.third);
                }
            }
        }
        reverse(verts.begin(), verts.end());
        for (int x : verts) {
            int v = x;
            int a = l[x], b = r[x];
            if (r[a] != b) swap(a, b);
            r[a] = v;
            r[v] = b;
            l[v] = a;
            l[b] = v;
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            cout << s + 1 << ' ';
            s = r[s];
        }
        cout << '\n';
        for (int x : ans) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
}