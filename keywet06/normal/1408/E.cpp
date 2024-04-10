#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 2e5 + 10;

struct edge {
    int u, v, w;
    bool operator<(const edge &A) const { return w > A.w; }
};

int m, n, a[N], b[N], fa[N];
int64 sum = 0;

int getf(int x) { return x == fa[x] ? x : fa[x] = getf(fa[x]); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n + m; i++) fa[i] = i;
    vector<edge> vec;
    for (int i = 1; i <= m; i++) {
        int sz, x;
        cin >> sz;
        while (sz--)
            cin >> x, vec.pb((edge){x, n + i, a[i] + b[x]}), sum += a[i] + b[x];
    }
    sort(vec.begin(), vec.end());
    for (auto t : vec) {
        int x = getf(t.u), y = getf(t.v);
        if (x != y) fa[x] = y, sum -= t.w;
    }
    cout << sum << '\n';
    return 0;
}