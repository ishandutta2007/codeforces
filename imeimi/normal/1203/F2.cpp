#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

const int inf = 1e8;
int n, r;
int dp[60001];
int tp[60001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> r;
    vector<pii> P, N;
    for (int i = 0; i < n; ++i) {
        pii p;
        cin >> p.fs >> p.se;
        if (p.se < 0) N.push_back(p);
        else P.push_back(p);
    }
    sort(P.begin(), P.end());
    int ans1 = 0;
    for (pii i : P) {
        if (r < i.fs) break;
        r += i.se;
        ++ans1;
    }
    for (int i = 0; i <= 60000; ++i) dp[i] = tp[i] = -inf;
    dp[r] = ans1;
    sort(N.begin(), N.end(), [&](pii a, pii b) {
        return a.se + a.fs > b.se + b.fs;
    });
    for (pii i : N) {
        for (int j = 0; j <= 60000; ++j) tp[j] = dp[j];
        for (int j = i.fs; j <= 60000; ++j) {
            if (dp[j] < 0) continue;
            if (j + i.se < 0) continue;
            tp[j + i.se] = max(tp[j + i.se], dp[j] + 1);
        }
        for (int i = 0; i <= 60000; ++i) {
            dp[i] = tp[i];
        }
    }
    int ans = 0;
    for (int i = 0; i <= 60000; ++i) ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}