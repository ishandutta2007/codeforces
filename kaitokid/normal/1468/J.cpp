#include <bits/stdc++.h>
using namespace std;

#define     F       first
#define     S       second
typedef pair<int, int>  pi;
typedef long long       ll;

int FindSet(int u, vector<int>& par) {
    if (par[u] == u) {
        return u;
    }
    else {
        return par[u] = FindSet(par[u], par);
    }
}

void MergeSets(int u, int v, vector<int>& par, vector<int>& r) {
    int parU = FindSet(u, par);
    int parV = FindSet(v, par);

    if (r[parU] == r[parV]) {
        ++r[parV];
    }
    else if (r[parU] > r[parV]) {
        swap(parU, parV);
    }

    par[parU] = parV;
}

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> par(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }

    vector< pair<int, pi> > edges;

    for (int i = 0; i < m; ++i) {
        int x, y, s;
        cin >> x >> y >> s;
        edges.push_back({s, {x, y}});
    }

    sort(edges.begin(), edges.end());

    ll edgesSum = 0;
    for (int i = 0; i < m; ++i) {
        int s = edges[i].F;
        int x = edges[i].S.F;
        int y = edges[i].S.S;

        if (FindSet(x, par) != FindSet(y, par)) {
            MergeSets(x, y, par, r);

            if (s > k) {
                edgesSum += s - k;
            }
        }
    }

    if (edgesSum) {
        cout << edgesSum << "\n";
        return;
    }

    ll answer = LLONG_MAX;
    for (int i = 0; i < m; ++i) {
        answer = min(answer, (ll)abs(k - edges[i].F));
    }

    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}