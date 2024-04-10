#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

vector <pair<int, int> > v;

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> j;
        v.push_back({j, i});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (i = 1; i <= v.size(); ++i) {
        ans += (i - 1) * v[v.size() - i].fi + 1;
    }
    cout << ans << "\n";
    for (i = v.size() - 1; i >= 0; --i)
        cout << v[i].se << ' ';
}