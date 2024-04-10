#include <bits/stdc++.h>
#pragma GCC optimize 03
//#define int long long
#define fi first
#define se second
using namespace std;
const int N = 122;
const int mod = 998244353;

int minr = 2e9;
int m[N][N], n;
int top = 0, v[10];
vector <pair<int, int> > t[N][N];

bool good(int x, vector <int> & v) {
    for (int i = 0; i < v.size(); ++i)
    if (v[i] == x)
        return false;
    return true;
}

void pruf() {
    v[++top] = 1;
    int ans = 0;
    for (int i = 0; i < top; ++i) {
        int tkans = 2e9;
        for (auto p : t[v[i]][v[i + 1]]) {
                int l = p.se;
        if ((top < 2 || l != v[1]) && (top < 3 || l != v[2]) && (top < 4 || l != v[3]) && (top < 5 || l != v[4]))
            tkans = min(tkans, p.fi);
        }
        ans += tkans;
    }
    --top;
    minr = min(minr, ans);
}

int cn = 0;

void rec(int cnt) {
    ++cn;
    if (cnt == 0) {
        pruf();
        return;
    }
    for (int i = 1; i <= n; ++i) {
        ++top;
        v[top] = i;
        rec(cnt - 1);
        --top;
    }
}


void solve() {
    int i, j, k, l;
    cin >> n >> k;
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
        cin >> m[i][j];
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
        for (l = 1; l <= n; ++l)
        if (l != i && l != j)
            t[i][j].push_back({m[i][l] + m[l][j], l});
        sort(t[i][j].begin(), t[i][j].end());
        if (t[i][j].size() > 4)
            t[i][j].resize(4);
    }
    v[0] = 1;
    top = 0;
    rec(k / 2 - 1);
    cout << minr;

}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif // local
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}