#include "bits/stdc++.h"

using namespace std;

const int N = 1e6 + 1;
vector<vector<int>> d(N);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pos(N);
    vector<int> id(N, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    vector<int> l(n), r(n);
    {
        vector<pair<int, int>> tmp = {{-1, -1}};
        for (int i = 0; i < n; i++) {
            while (tmp.back().first >= a[i]) {
                tmp.pop_back();
            }
            l[i] = tmp.back().second;
            tmp.push_back({a[i], i});
        }
    }
    {
        vector<pair<int, int>> tmp = {{-1, n}};
        for (int i = n - 1; i >= 0; i--) {
            while (tmp.back().first >= a[i]) {
                tmp.pop_back();
            }
            r[i] = tmp.back().second;
            tmp.push_back({a[i], i});
        }
    }
    vector<int> l2(n), r2(n);
    {
        vector<pair<int, int>> tmp = {{N, -1}};
        for (int i = 0; i < n; i++) {
            while (tmp.back().first <= a[i]) {
                tmp.pop_back();
            }
            l2[i] = tmp.back().second;
            tmp.push_back({a[i], i});
        }
    }
    {
        vector<pair<int, int>> tmp = {{N, n}};
        for (int i = n - 1; i >= 0; i--) {
            while (tmp.back().first < a[i]) {
                tmp.pop_back();
            }
            r2[i] = tmp.back().second;
            tmp.push_back({a[i], i});
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto x : d[a[i]]) {
            int& uk = id[x];
            while (uk + 1 <  (int) pos[x].size() && pos[x][uk + 1] <= i) {
                uk++;
            }
            int cl = (uk == -1 ? -1 : pos[x][uk]);
            int cr = (uk + 1 == (int) pos[x].size() ? -1 : pos[x][uk + 1]);
            if (cl != -1 && r[cl] < i) {
                cl = -1;
            }
            if (cr != -1 && l[cr] > i) {
                cr = -1;
            }
            if (cl == -1 && cr == -1) {
                continue;
            }
            long long was = ans;
            int R = r2[i];
            if (cr != -1) {
                R = min(R, r[cr]);
            }
            if (cl != -1) {
                R = min(R, r[cl]);
            }
            int L = l2[i];
            if (cr != -1) {
                L = max(L, l[cr]);
            }
            if (cl != -1) {
                L = max(L, l[cl]);
            }
            ans += (R - i) * 1ll * (i - L);
            if (cr != -1) {
                R = min(R, cr);
            }
            if (cl != -1) {
                L = max(L, cl);
            }
            ans -= (R - i) * 1ll * (i - L);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            d[j].push_back(i);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}