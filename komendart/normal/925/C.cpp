#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define int long long

const int maxbit = 60;

vector<int> a[maxbit];

vector<int> merge(const vector<int> ans, int bit, const vector<int> a) {
    vector<int> res;
    res.reserve(sz(ans) + sz(a));
    int p = 0;
    if (p < sz(a)) {
        res.push_back(a[p++]);
    }
    for (auto i: ans) {
        res.push_back(i);
        if (p < sz(a)) {
            if (i & bit) {
                res.push_back(a[p++]);
            }
        }
    }
    if (p < sz(a)) {
        cout << "No\n";
        exit(0);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int d = 0;
        for (int t = x; t > 0; t >>= 1) ++d;
        a[d - 1].push_back(x);
    }
    vector<int> ans;
    for (int i = maxbit - 1; i >= 0; --i) {
        ans = merge(ans, 1LL << i, a[i]);
    }
    cout << "Yes\n";
    for (auto i: ans) {
        cout << i << ' ';
    }
}