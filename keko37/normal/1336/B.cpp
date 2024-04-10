#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n[3];
vector <llint> v[3];

llint f (llint x, llint y, llint z) {
    return (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n[0] >> n[1] >> n[2];
        for (int i = 0; i < 3; i++) {
            v[i].clear();
            for (int j = 0; j < n[i]; j++) {
                int x; cin >> x;
                v[i].push_back(x);
            }
            sort(v[i].begin(), v[i].end());
        }
        llint sol = 3e18;
        for (int i = 0; i < 3; i++) {
            int a = (i + 1) % 3, b = (i + 2) % 3;
            for (int j = 0; j < n[i]; j++) {
                int val = v[i][j];

                int pa = lower_bound(v[a].begin(), v[a].end(), val) - v[a].begin();
                int pb = upper_bound(v[b].begin(), v[b].end(), val) - v[b].begin() - 1;
                if (pa < v[a].size() && pb >= 0) sol = min(sol, f(val, v[a][pa], v[b][pb]));

                pa = upper_bound(v[a].begin(), v[a].end(), val) - v[a].begin() - 1;
                pb = lower_bound(v[b].begin(), v[b].end(), val) - v[b].begin();
                if (pa >= 0 && pb < v[b].size()) sol = min(sol, f(val, v[a][pa], v[b][pb]));
            }
        }
        cout << sol << '\n';
    }
    return 0;
}