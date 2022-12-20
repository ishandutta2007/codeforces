#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

int i, j, n, m;
vector <pair<int, int> > v1, v2, p;

int main() {
    int x1[N], y1[N], x2[N], y2[N];
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        v1.push_back({x1[i], y1[i]});
        v2.push_back({y1[i], x1[i]});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (i = 0; i < 2; ++i)
    for (j = 0; j < 2; ++j)
        p.push_back({v1[v1.size() - 1 - i].first, v2[v2.size() - 1 - j].first});
    for (i = 0; i < 4; ++i) {
        int cnt = 0;
        for (j = 0; j < n; ++j)
        if (x1[j] <= p[i].first && p[i].first <= x2[j] && y1[j] <= p[i].second && p[i].second <= y2[j])
            ++cnt;
        if (cnt >= n - 1) {
            cout << p[i].first << ' ' << p[i].second << endl;
            return 0;
        }
    }
}