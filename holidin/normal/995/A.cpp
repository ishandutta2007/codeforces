#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 200;

int main() {
    int i, j, a[N], c[N], x1[N], y1[N], x2[N], y2[N], n, k, p[N];
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = i;
        x1[i] = 1;
        y1[i] = i;
    }
    for (i = 1; i <= n; ++i) {
        cin >> c[i];
        x2[i] = 2;
        y2[i] = i;
    }
    for (i = 1; i <= n; ++i) {
        cin >> c[n + n - i + 1];
        x2[n + i] = 3;
        y2[n + n - i + 1] = i;
    }
    for (i = 1; i <= n; ++i) {
        cin >> a[n + i];
        x1[n + i] = 4;
        y1[n + i] = i;
        p[n + n - i + 1] = n + i;
    }
    vector <pair<pair<int, int>, int > > v;
    while (true) {
        bool flag = false;
        for (i = 1; i <= 2 * n; ++i)
        if (c[i] != 0) {
            if (a[p[i]] == c[i]) {
                flag = true;
                v.push_back({{x1[p[i]], y1[p[i]]}, c[i]});
                c[i] = 0;
            }
            int nx = i + 1;
            if (nx > 2 * n)
                nx = 1;
            if (c[nx] == 0 && c[i] != 0) {
                flag = true;
                v.push_back({{x2[nx], y2[nx]}, c[i]});
                c[nx] = c[i];
                //cout << i << ' '<< nx << endl;
                c[i] = 0;
            }
        }
        if (!flag)
            break;
    }
    for (i = 1; i <= 2 * n; ++i)
    if (c[i] != 0) {
        cout << -1;
        return 0;
    }
    cout << v.size() << "\n";
    for (i = 0; i < v.size(); ++i)
        cout << v[i].se << ' ' << v[i].fi.fi << ' ' << v[i].fi.se << "\n";
}