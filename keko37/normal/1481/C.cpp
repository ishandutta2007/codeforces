#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n, m;
int a[MAXN], b[MAXN], c[MAXN], ok[MAXN], sol[MAXN];
vector <int> v[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            v[i].clear();
            ok[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            ok[b[i]] = i;
            if (a[i] != b[i]) v[b[i]].push_back(i);
        }
        for (int i = 1; i <= m; i++) {
            sol[i] = -1;
            cin >> c[i];
            if (ok[c[i]]) {
                if (!v[c[i]].empty()) {
                    sol[i] = v[c[i]].back();
                    v[c[i]].pop_back();
                } else {
                    sol[i] = ok[c[i]];
                }
            }
        }
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            if (!v[i].empty()) ok = 0;
        }
        if (!ok || sol[m] == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i <= m; i++) {
                if (sol[i] == -1) sol[i] = sol[m];
                cout << sol[i] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}