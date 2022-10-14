#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

llint t, n, m;
llint a[MAXN][MAXN];

llint calc (int x, int y) {
    vector <pi> v;
    v.push_back({x, y});
    v.push_back({n-1 - x, y});
    v.push_back({x, m-1 - y});
    v.push_back({n-1 - x, m-1 - y});
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector <int> r;
    for (auto par : v) {
        r.push_back(a[par.first][par.second]);
    }
    sort(r.begin(), r.end());
    llint res = 0, med = r[r.size() / 2];
    for (int i = 0; i < r.size(); i++) {
        res += abs(r[i] - med);
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        llint sol = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; 2 * i < n; i++) {
            for (int j = 0; 2 * j < m; j++) {
                sol += calc(i, j);
            }
        }
        cout << sol << '\n';
    }
    return 0;
}