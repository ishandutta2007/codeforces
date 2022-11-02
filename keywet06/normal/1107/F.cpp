#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = 505;

int n;

int64 dp[N][N];

pair<int, pair<int, int>> o[N];

template <typename _Tp>
inline _Tp &mad(_Tp &x, _Tp y) {
    return x = std::max(x, y);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        o[i] = make_pair(b, make_pair(a, k));
    }
    sort(o + 1, o + n + 1);
    reverse(o + 1, o + n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int k = i; k >= 0; --k) {
            for (int j = i - k; j >= 0; --j) {
                if (j) {
                    mad(dp[j][k], dp[j - 1][k] + o[i].second.first -
                                      o[i].first * int64(j - 1));
                }
                if (k) {
                    mad(dp[j][k], dp[j][k - 1] + o[i].second.first -
                                      o[i].first * int64(o[i].second.second));
                }
            }
        }
    }
    printf("%lld\n", *max_element(dp[0], dp[n] + n + 1));
    return 0;
}