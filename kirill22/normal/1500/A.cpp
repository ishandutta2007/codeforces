#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double

const int N = 1e7 + 5;
int gist[N], gist2[N], gist3[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        gist3[g[i]]++;
    }
    int x = -1, y = -1;
    for (int i = 0; i < N; i++) {
        if (gist3[i] > 3) {
            vector<int> ans;
            for (int j = 0; j < n; j++) if (g[j] == i && sz(ans) < 4) ans.pb(j);
            cout << "YES" << endl;
            for (auto x : ans) cout << x + 1 << " ";
            return 0;
        }
        if (gist3[i] > 1) {
            if (x == -1) x = i;
            else y = i;
        }
    }
    if (y != -1) {
        vector<int> ans, ans2;
        for (int j = 0; j < n; j++) {
            if (g[j] == x && sz(ans) < 2) ans.pb(j);
            if (g[j] == y && sz(ans2) < 2) ans2.pb(j);
        }
        cout << "YES" << endl;
        cout << ans[0] + 1 << " " << ans2[0] + 1 << " " << ans[1] + 1 << " " << ans2[1] + 1;
        return 0;
    }
    while (g.size() > 1500) g.pop_back();
    n = g.size();
    for (auto x : g) gist[x]++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            gist2[g[i] + g[j]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int s = g[i] + g[j];
            int cnt = gist2[s] - 2;
            cnt -= 2 * (gist[s - g[i]] - 1);
            cnt -= 2 * (gist[s - g[i]] - 1);
            if (cnt > 0) {
                for (int i2 = 0; i2 < n; i2++) {
                    for (int j2 = 0; j2 < n; j2++) {
                        if (i2 == j2) continue;
                        int s2 = g[i2] + g[j2];
                        if (s2 != s) continue;
                        auto el = make_pair(i2, j2);
                        if (el.fi != i && el.se != i && el.fi != j && el.se != j) {
                            cout << "YES" << endl;
                            cout << i + 1 << " " << j + 1 << " " << el.fi + 1 << " " << el.se + 1;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "NO";
}