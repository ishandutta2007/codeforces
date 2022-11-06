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
vector<int> edge[200001];

int mx[200001], cn[200001];

void dfs1(int x, int p) {
    mx[x] = 0;
    cn[x] = 1;
    int child = 0;
    for (int i : edge[x]) {
        if (i == p) continue;
        dfs1(i, x);
        mx[x] += mx[i];
        cn[x] &= cn[i];
        child += cn[i];
    }
    mx[x] += child / k;
    cn[x] &= (child % k == 0);
}

int umx[200001], ucn[200001];
int dfs2(int x, int p) {
    int sum = umx[x], cnt0 = !ucn[x], child = p && ucn[x];
    for (int i : edge[x]) {
        if (i == p) continue;
        sum += mx[i];
        cnt0 += !cn[i];
        child += cn[i];
    }
    int ret = sum + child / k;
    for (int i : edge[x]) {
        if (i == p) continue;
        umx[i] = sum - mx[i] + (child - cn[i]) / k;
        ucn[i] = (cnt0 - !cn[i] == 0) && (child - cn[i]) % k == 0;
        ret = max(ret, dfs2(i, x));
    }
    return ret;
}

int solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) edge[i].clear();
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs1(1, 0);
    umx[1] = 0;
    ucn[1] = 1;
    return dfs2(1, 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}