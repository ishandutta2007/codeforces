#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 5001;
vector <int> p[N], simple, v[N];
int cnt[N];
bool used[N];

int dist(vector <int> &a, vector <int> &b) {
    int ans = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    if (a[i] != b[i]) {
        ans += abs(a[i] - b[i]);
        while (i > 0) {
            --i;
            ans += a[i] + b[i];
        }
        break;
    }
    return ans;
}

void solve() {
    int i, j, k, n;
    for (i = 2; i < N; ++i)
    if (v[i].size() == 0) {
        simple.push_back(i);
        for (j = i; i * j < N; ++j)
            v[i * j].push_back(i);
    }
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> j;
        ++cnt[j];
    }
    for (i = 0; i < N; ++i) {
        p[i].resize(simple.size());
        for (j = 0; j < simple.size(); ++j) {
            int x = simple[j];
            for (int l = 1; x <= i; ++l) {
                p[i][j] += i / x;
                x *= simple[j];
            }
        }
    }
    for (i = 0; i < N; ++i)
        used[i] = 1;
    int l = simple.size() - 1;
    vector <int> v(simple.size());
    while (l >= 0) {
        int cntf = 0;
        for (i = 0; i < N; ++i)
        if (used[i] && p[i][l] > v[l])
            cntf += cnt[i];
        if (cntf > n / 2) {
            for (i = 0; i < N; ++i)
            if (used[i] && p[i][l] <= v[l])
                used[i] = 0;
            ++v[l];
        } else {
            for (i = 0; i < N; ++i)
            if (used[i] && p[i][l] > v[l])
                used[i] = 0;
            --l;
        }
    }
    int ans = 0;
    for (i = 0; i < N; ++i)
        ans += dist(v, p[i]) * cnt[i];
    cout << ans;
}


signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();

}