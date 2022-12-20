#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 100;

vector <pair<pair<int, int>, pair<int, int> > > f(int n, vector <pair<int, int> > pos) {
    int x[N], y[N], m[N][N], i, j;
    vector <pair<pair<int, int>, pair<int, int> > > ans;
    vector <pair<int, int> > v;
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
        m[i][j] = 0;
    for (i = 0; i < pos.size(); ++i) {
        x[i + 1] = pos[i].first;
        y[i + 1] = pos[i].second;
        m[x[i + 1]][y[i + 1]] = i + 1;
        v.push_back({x[i + 1], i + 1});
    }
    sort(v.begin(), v.end());
    while (true) {
        int c = -1;
        bool flag2 = false;
        for (i = 0; i < pos.size(); ++i)
        if (x[v[i].second] != i + 1) {
            bool flag = true;
            flag2 = true;
            for (int j = min(x[v[i].second], i + 1); j <= max(x[v[i].second], i + 1); ++j)
            if (m[j][y[v[i].second]] > 0 && j != x[v[i].second])
                flag = false;
            if (flag)
                c = i;
        }
        if (c < 0)
            break;
        m[x[v[c].second]][y[v[c].second]] = 0;
        while (x[v[c].second] < c + 1) {
            ans.push_back({{x[v[c].second], y[v[c].second]}, {x[v[c].second] + 1, y[v[c].second]}});
            ++x[v[c].second];
        }
        while (x[v[c].second] > c + 1) {
            ans.push_back({{x[v[c].second], y[v[c].second]}, {x[v[c].second] - 1, y[v[c].second]}});
            --x[v[c].second];
        }
        m[x[v[c].second]][y[v[c].second]] = v[c].second;
    }
    for (i = 1; i <= pos.size(); ++i) {
        while (y[i] < i) {
            ans.push_back({{x[i], y[i]}, {x[i], y[i] + 1}});
            ++y[i];
        }
        while (y[i] > i) {
            ans.push_back({{x[i], y[i]}, {x[i], y[i] - 1}});
            --y[i];
        }
    }
    for (i = 1; i <= pos.size(); ++i) {
        while (x[i] < i) {
            ans.push_back({{x[i], y[i]}, {x[i] + 1, y[i]}});
            ++x[i];
        }
        while (x[i] > i) {
            ans.push_back({{x[i], y[i]}, {x[i] - 1, y[i]}});
            --x[i];
        }
    }
    return ans;
}

int i, j, n, m, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector <pair<int, int> > need, pos;
    cin >> n >> m;
    for (i = 1; i <= m; ++i) {
        cin >> a >> b;
        pos.push_back({a, b});
    }
    for (i = 1; i <= m; ++i) {
        cin >> a >> b;
        need.push_back({a, b});
    }
    vector <pair<pair<int, int>, pair<int, int> > > ans1 = f(n, pos), ans2 = f(n, need);
    cout << ans1.size() + ans2.size() << "\n";
    for (i = 0; i < ans1.size(); ++i)
        cout << ans1[i].fi.fi << ' ' << ans1[i].fi.se << ' ' << ans1[i].se.fi << ' ' << ans1[i].se.se << "\n";
    for (i = ans2.size() - 1; i >= 0; --i)
        cout << ans2[i].se.fi << ' ' << ans2[i].se.se << ' ' << ans2[i].fi.fi << ' ' << ans2[i].fi.se  << "\n";
}