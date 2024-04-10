#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef pair<int, int> pt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<pt, int> allEdges;
    set<pt> difPairs, eqPairs;

    fore(q, 0, m) {
        char tp;
        cin >> tp;
        if (tp == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;

            if (allEdges.count({v, u})) {
                if (allEdges[{v, u}] == c)
                    eqPairs.emplace(min(u, v), max(u, v));
                else
                    difPairs.emplace(min(u, v), max(u, v));
            }
            allEdges[{u, v}] = c;

        } else if (tp == '-') {
            int u, v;
            cin >> u >> v;
            if (eqPairs.count({min(u, v), max(u, v)}))
                eqPairs.erase({min(u, v), max(u, v)});
            if (difPairs.count({min(u, v), max(u, v)}))
                difPairs.erase({min(u, v), max(u, v)});

            allEdges.erase({u, v});
        } else {
            int k;
            cin >> k;

            bool hasAns = !eqPairs.empty();
            if (k & 1) hasAns |= !difPairs.empty();
            cout << (hasAns ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}