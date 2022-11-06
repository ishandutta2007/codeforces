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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n;
vector<int> edge[100001];
int ans[100000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(i);
        edge[y].push_back(i);
    }
    int v = 0;
    for (int i = 1; i <= n; ++i) {
        if (int(edge[i].size()) < 3) continue;
        for (int j : edge[i]) {
            ans[j] = ++v;
        }
        break;
    }
    for (int i = 1; i < n; ++i) {
        if (ans[i]) continue;
        ans[i] = ++v;
    }
    for (int i = 1; i < n; ++i) {
        printf("%d\n", ans[i] - 1);
    }
    return 0;
}