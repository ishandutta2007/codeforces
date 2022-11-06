#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

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

int n, q;
vector<int> V[200001];
int A[200001];
int S[200001];
int all[200001];
int mx[200001];

int par[200001];
int find(int x) {
    if (par[x]) return par[x] = find(par[x]);
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        V[A[i]].push_back(i);
    }
    for (int i = 1; i <= 200000; ++i) {
        if (V[i].empty()) continue;
        mx[i] = all[i] = V[i].size();
        ++S[V[i][0]];
        --S[V[i].back()];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        S[i] += S[i - 1];
        if (S[i] > 0) {
            int x = find(A[i]);
            int y = find(A[i + 1]);
            if (x == y) continue;
            par[y] = x;
            all[x] += all[y];
            mx[x] = max(mx[x], mx[y]);
        }
    }
    for (int i = 1; i <= 200000; ++i) {
        ans += all[i] - mx[i];
    }
    printf("%d\n", ans);
    return 0;
}