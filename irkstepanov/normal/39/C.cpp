#include <bits/stdc++.h>

#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

struct segment
{
    int l, r;
    int id;
};

int main()
{

    //ifstream cin("input.txt");

    int k;
    cin >> k;

    vector<segment> v(k);
    vector<int> sorted;
    for (int i = 0; i < k; ++i) {
        int c, r;
        cin >> c >> r;
        v[i].l = c - r;
        v[i].r = c + r;
        v[i].id = i;
        sorted.pb(v[i].l);
        sorted.pb(v[i].r);
    }
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    for (int i = 0; i < k; ++i) {
        v[i].l = lower_bound(all(sorted), v[i].l) - sorted.begin();
        v[i].r = lower_bound(all(sorted), v[i].r) - sorted.begin();
    }

    int n = sz(sorted);
    map<pii, vector<int> > m;
    vector<vector<int> > lf(n);

    for (int i = 0; i < k; ++i) {
        m[{v[i].l, v[i].r}].pb(i);
        lf[v[i].r].pb(i);
    }

    vector<vector<int> > dp(n, vector<int>(n));
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            for (int t : lf[j]) {
                int l = v[t].l;
                if (l <= i) {
                    continue;
                }
                dp[i][j] = max(dp[i][j], dp[i][l] + dp[l][j]);
            }
            if (j != i) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
            if (m.count({i, j})) {
                vector<int> vv = m[{i, j}];
                dp[i][j] += sz(vv);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

    queue<pii> q;
    q.push({0, n - 1});

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        int dd = 0;
        if (m.count({i, j})) {
            for (int t : m[{i, j}]) {
                cout << t + 1 << " ";
            }
            vector<int> vv = m[{i, j}];
            dd = sz(vv);
        }
        if (i == j) {
            continue;
        }
        if (dp[i][j] - dd == dp[i][j - 1]) {
            q.push({i, j - 1});
            continue;
        }
        for (int t : lf[j]) {
            int l = v[t].l;
            if (l <= i) {
                continue;
            }
            if (dp[i][j] - dd == dp[i][l] + dp[l][j]) {
                q.push({i, l});
                q.push({l, j});
                break;
            }
        }
    }

    cout << "\n";

}