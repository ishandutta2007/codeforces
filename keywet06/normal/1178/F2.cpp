#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int M = 1000100;
const int N = 510;
const int64 P = 998244353;

int n, m;
int a[M], lo[N], hi[N];

int64 fc[N];
int64 dp[N][N];

vector<int> oc[N];
vector<pair<int, pair<int, int> > > v;

int64 get_dp(int x, int y) {
    if (x == y) return 1;
    --y;
    if (lo[a[x]] == x && hi[a[y]] == y) return dp[a[x]][a[y]];
    return 0;
}

bool contains(int x, int y, int k) {
    if (lo[k] > y || hi[k] < x) return false;
    vector<int>::iterator it = lower_bound(oc[k].begin(), oc[k].end(), x);
    if (it == oc[k].end() || *it > y) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < N; ++i) {
        oc[i].clear();
        lo[i] = 1e9;
        hi[i] = -1;
    }

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        --k;
        a[i] = k;
        oc[k].push_back(i);
        lo[k] = min(lo[k], i);
        hi[k] = max(hi[k], i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = lo[i], y = hi[j];
            if (x > y || hi[i] > y || lo[j] < x) continue;
            bool bad = false;
            int mlo = 1e9;
            for (int k = 0; k < n; ++k) {
                if (!contains(x, y, k)) continue;
                if (lo[k] < x || hi[k] > y) {
                    bad = true;
                    break;
                }
                mlo = min(mlo, k);
            }
            if (bad) continue;
            v.push_back(make_pair(-mlo, make_pair(i, j)));
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) dp[i][j] = 0;
    }
    sort(v.begin(), v.end());
    for (int vx = 0; vx < v.size(); ++vx) {
        int ind = -v[vx].first, x = v[vx].second.first, y = v[vx].second.second;
        if (vx == 0 || v[vx].first != v[vx - 1].first) {
            fc[ind] = 1;
            for (int i = 0; i + 1 < oc[ind].size(); ++i) {
                int left = oc[ind][i], right = oc[ind][i + 1];
                fc[ind] = (fc[ind] * get_dp(left + 1, right)) % P;
            }
        }
        int hlo = lo[x], hhi = hi[y], ilo = lo[ind], ihi = hi[ind];
        int64 l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            if (lo[i] >= hlo && lo[i] <= ilo) {
                l += get_dp(hlo, lo[i]) * get_dp(lo[i], ilo);
                l %= P;
            }
            if (hi[i] <= hhi && hi[i] >= ihi) {
                r += get_dp(ihi + 1, hi[i] + 1) * get_dp(hi[i] + 1, hhi + 1);
                r %= P;
            }
        }
        dp[x][y] = (((l * r) % P) * fc[ind]) % P;
    }
    int l = a[0], r = a[m - 1];
    cout << dp[l][r] << "\n";
    return 0;
}