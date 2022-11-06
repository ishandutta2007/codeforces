#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

int n, k;
vector<int> T[2][2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        T[a][b].push_back(t);
    }
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
        sort(T[i][j].begin(), T[i][j].end());
    }
    if (int(T[0][1].size() + T[1][1].size()) < k) {
        printf("-1\n");
        return 0;
    }
    if (int(T[1][0].size() + T[1][1].size()) < k) {
        printf("-1\n");
        return 0;
    }
    int cnt = 0;
    llong sum = 0;
    for (; cnt < k && cnt < int(T[1][1].size()); ++cnt) sum += T[1][1][cnt];
    for (int i = 0; i < k - cnt; ++i) sum += T[0][1][i] + T[1][0][i];
    llong ans = sum;
    for (--cnt; cnt >= 0 && k - cnt - 1 < int(min(T[0][1].size(), T[1][0].size())); --cnt) {
        sum += T[0][1][k - cnt - 1] + T[1][0][k - cnt - 1] - T[1][1][cnt];
        ans = min(ans, sum);
    }
    printf("%lld\n", ans);
    return 0;
}