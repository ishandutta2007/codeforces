#include <bits/stdc++.h>

const int N = 200010;

using int64 = long long;

typedef std::pair<int, int64> Pair;

int n, m, cnt[4][N << 2];

int64 e, s, Q[N], S[4][N << 2];

Pair P[N];

std::vector<int64> A;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> e >> s >> n >> m;
    A.push_back(e);
    for (int i = 1; i <= n; ++i)
        std::cin >> P[i].first >> P[i].second, A.push_back(P[i].second), A.push_back(P[i].second + s);
    for (int i = 1; i <= m; ++i) std::cin >> Q[i], A.push_back(Q[i] + s);
    std::sort(A.begin(), A.end());
    A.erase(std::unique(A.begin(), A.end()), A.end());
    for (int i = 1; i <= n; ++i) {
        int l = std::lower_bound(A.begin(), A.end(), P[i].second) - A.begin();
        int r = std::lower_bound(A.begin(), A.end(), P[i].second + s) - A.begin();
        for (int k = 1; k <= P[i].first; ++k) cnt[k][l]++, cnt[k][r]--;
    }
    for (int k = 1; k <= 3; ++k) {
        for (int i = 1; i < A.size(); ++i) cnt[k][i] += cnt[k][i - 1];
        for (int i = 1; i < A.size(); ++i) S[k][i] = S[k][i - 1] + (cnt[k][i - 1] > 0 ? A[i] - A[i - 1] : 0);
    }
    int T = std::lower_bound(A.begin(), A.end(), e) - A.begin();
    for (int i = 1; i <= m; ++i) {
        int x = std::lower_bound(A.begin(), A.end(), Q[i] + s) - A.begin();
        int64 ans1, ans2;
        if (x >= T) {
            ans1 = 0, ans2 = 0;
        } else {
            int64 dis = A[T] - A[x];
            int64 dis3 = S[3][T] - S[3][x];
            int64 dis2 = S[2][T] - S[2][x];
            int64 dis1 = S[1][T] - S[1][x];
            if (dis == dis3) {
                ans1 = 0, ans2 = 0;
            } else if (dis == dis2) {
                ans1 = 0, ans2 = dis - dis3;
            } else if (dis == dis1) {
                ans1 = dis - dis2, ans2 = dis - dis3 - ans1;
            } else {
                ans1 = -1, ans2 = -1;
            }
        }
        std::cout << ans1 << " " << ans2 << std::endl;
    }
    return 0;
}