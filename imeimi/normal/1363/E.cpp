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

int n;
int A[200001], B[200001], C[200001];
vector<int> edge[200001];
int cnt[200001][2];

llong dfs(int x, int p) {
    if (B[x] != C[x]) cnt[x][B[x]] = 1;
    llong ans = 0;
    for (int i : edge[x]) {
        if (i == p) continue;
        A[i] = min(A[i], A[x]);
        ans += dfs(i, x);
        cnt[x][0] += cnt[i][0];
        cnt[x][1] += cnt[i][1];
    }
    int c = min(cnt[x][0], cnt[x][1]);
    ans += llong(c) * A[x];
    cnt[x][0] -= c;
    cnt[x][1] -= c;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i] >> B[i] >> C[i];
        sum += B[i] - C[i];
    }
    if (sum != 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    printf("%lld\n", dfs(1, 0) * 2);
    return 0;
}