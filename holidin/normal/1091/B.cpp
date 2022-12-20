#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int main() {
    int a, b, c, i, j, y, n, x;
    vector <pair<int, int> > v1, v2;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> x >> y;
        v1.push_back({x, y});
    }
    for (i = 0; i < n; ++i) {
        cin >> x >> y;
        v2.push_back({x, y});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << v1[0].fi + v2[v2.size() - 1].fi << ' ' << v1[0].se + v2[v2.size() - 1].se;
}