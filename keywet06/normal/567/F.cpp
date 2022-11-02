#include <bits/stdc++.h>

typedef long long int64;

const int N = 40 * 2;

using namespace std;

int64 dp[N][N];

bool mark[N][N];

vector<int> more[N], least[N];

bool equal(int x, int y) {
    return !(binary_search(more[x].begin(), more[x].end(), y) ||
             binary_search(more[y].begin(), more[y].end(), x));
}

bool Less(int x, int l, int r) {
    int it =
        lower_bound(least[x].begin(), least[x].end(), l) - least[x].begin();
    return it == least[x].size() || least[x][it] > r;
}

int64 solve(int l, int r) {
    if (mark[l][r]) return dp[l][r];
    mark[l][r] = true;
    if (r - l == 1) return dp[l][r] = equal(l, r);
    int64 ans = 0;
    if (equal(l, r) && Less(l, l + 1, r - 1) && Less(r, l + 1, r - 1))
        ans += solve(l + 1, r - 1);
    if (equal(l, l + 1) && Less(l, l + 2, r) && Less(l + 1, l + 2, r))
        ans += solve(l + 2, r);
    if (equal(r - 1, r) && Less(r - 1, l, r - 2) && Less(r, l, r - 2))
        ans += solve(l, r - 2);
    return dp[l][r] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k, x, y;
    string s;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x >> s >> y, --x, --y;
        if (s == ">=") swap(x, y), s = "<=";
        if (s == ">") swap(x, y), s = "<";
        if (x == y && s == "<") return (cout << 0 << endl), 0;
        if (s == "=") least[x].push_back(y), least[y].push_back(x);
        if (s == "<=") least[y].push_back(x);
        if (s == "<") more[y].push_back(x), least[y].push_back(x);
    }
    for (int i = 0; i < 2 * n; ++i) {
        sort(least[i].begin(), least[i].end());
        sort(more[i].begin(), more[i].end());
    }
    cout << solve(0, 2 * n - 1) << endl;
    return 0;
}