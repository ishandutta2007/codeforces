#include <bits/stdc++.h>
using namespace std;
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector <pair <int, int> > id;
    queue <int> q;
    for (int i = 0; i < n; ++ i) {
        int d, s; cin >> d >> s;
        id.emplace_back(d, s);
        if (d == 1) q.push(i);
    }
    vector <pair <int, int> > g;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (id[u].first == 0) continue;
        int fa = id[u].second;
        id[fa].first --;
        id[fa].second ^= u;
        if (id[fa].first == 1) q.push(fa);
        g.emplace_back(fa, u);
    }
    cout << g.size() << endl;
    for (pair <int, int> p : g) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}