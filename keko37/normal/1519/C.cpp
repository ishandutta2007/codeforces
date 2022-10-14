#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n;
int u[MAXN], s[MAXN];
vector <llint> v[MAXN];
vector <pi> r;

llint solve (int k) {
    llint sol = 0;
    for (int i = 0; i < r.size(); i++) {
        int ind = r[i].second;
        llint val = r[i].first;
        if (val < k) break;
        val -= val % k;
        sol += v[ind][val - 1];
    }
    return sol;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        r.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> u[i];
            v[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            v[u[i]].push_back(s[i]);
        }
        for (int i = 1; i <= n; i++) {
            sort(v[i].begin(), v[i].end());
            reverse(v[i].begin(), v[i].end());
            for (int j = 1; j < v[i].size(); j++) {
                v[i][j] += v[i][j - 1];
            }
            r.push_back({v[i].size(), i});
        }
        sort(r.begin(), r.end());
        reverse(r.begin(), r.end());
        for (int k = 1; k <= n; k++) {
            cout << solve(k) << " ";
        }
        cout << '\n';
    }
    return 0;
}