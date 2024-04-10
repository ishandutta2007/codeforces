#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int mxN = 20e6;
const int inf = 2e9 + 1;

vector <pair<int, int> > v;

int main() {
    int i, j, n, k, a, b, l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> l >> r;
        v.push_back({l, 1});
        v.push_back({r + 1, -1});
    }
    sort(v.begin(), v.end());
    int bl = 0, bg = -2e9, bl1 = 0;
    i = 0;
    vector <pair<int, int> > ans;
    while (i < v.size()) {
        j = i;
        int mn = 0;
        while (j < v.size() && v[j].fi == v[i].fi) {
            bl += v[j].se;
            if (v[j].se < 0)
                mn += v[j].se;
            ++j;
        }
        if (bl1 + mn < k && bg > -2e9) {
            ans.push_back({bg, v[i].fi - 1});
            bg = -2e9;
        }
        if (bl >= k && bg == -2e9)
            bg = v[i].fi;
        bl1 = bl;
        i = j;
    }
    cout << ans.size() << endl;
    for (i = 0;  i< ans.size(); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << "\n";
}