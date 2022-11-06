#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, m;
int X[300001];
int Y[300001];
llong Xs[300001];
llong Ys[300001];
vector<int> hate[300001];
int ord[300000];
int rev[300001];
llong ans[300001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> X[i] >> Y[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        hate[a].push_back(b);
        hate[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) ord[i] = i + 1;
    sort(ord, ord + n, [&](int i, int j) { return X[i] - Y[i] < X[j] - Y[j]; });
    for (int i = 0; i < n; ++i) rev[ord[i]] = i;
    for (int i = 0; i < n; ++i) {
        Xs[i + 1] = Xs[i] + X[ord[i]];
        Ys[i + 1] = Ys[i] + Y[ord[i]];
    }
    for (int it = 0; it < n; ++it) {
        int i = ord[it];
        llong ret = (llong)Y[i] * it + Xs[it] + (llong)X[i] * (n - it - 1) + (Ys[n] - Ys[it + 1]);
        for (int j : hate[i]) {
            if (rev[j] < it) {
                ret -= Y[i];
                ret -= X[j];
            }
            else {
                ret -= X[i];
                ret -= Y[j];
            }
        }
        ans[i] = ret;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", ans[i]);
    }
    return 0;
}