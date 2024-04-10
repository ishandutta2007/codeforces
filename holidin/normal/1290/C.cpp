#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define double long double
using namespace std;
const int N = 3e5 + 1;
const int mod = 1e9 + 7;

vector <int> v[N], vt[N], vs[N];
int cnt[N][2], c[N], type[N], fix[N];

void uni1(int a, int b) {
    if (a == b)
        return;
    if (v[a].size() < v[b].size())
        swap(a, b);
    for (int i = 0; i < v[b].size(); ++i) {
        v[a].push_back(v[b][i]);
        c[v[b][i]] = a;
    }
    v[b].clear();
}


int ans = 0;


int cost(int a) {
    if (fix[a] == -1)
        return min(cnt[a][0], cnt[a][1]);
    else
        return cnt[a][fix[a]];
}

void uni(int a, int b, int cxor) {
    if (a == b)
        return;
    if (v[a].size() < v[b].size())
        swap(a, b);
    ans -= cost(a) + cost(b);
    for (int i = 0; i < v[b].size(); ++i) {
        v[a].push_back(v[b][i]);
        c[v[b][i]] = a;
        type[v[b][i]] ^= cxor;
        ++cnt[a][type[v[b][i]]];
    }
    if (fix[b] >= 0)
        fix[a] = fix[b] ^ cxor;
    ans += cost(a);
    v[b].clear();
}

bool use[N];

void solve() {
    string s;
    int i, j, k, n, m, q, l, r, t;
    cin >> n >> k;
    cin >> s;
    for (i = 1; i <= k; ++i) {
        cin >> t;
        fix[i] = -1;
        v[i].push_back(i);
        c[i] = i;
        for (j = 0; j < t; ++j) {
            cin >> l;
            vs[l].push_back(i);
            vt[i].push_back(l);
        }
    }
    for (i = 1; i <= k; ++i) {
        v[i].clear();
        v[i].push_back(i);
        cnt[i][0] = 1;
        cnt[i][1] = 0;
        c[i] = i;
    }
    for (i = 1; i <= n; ++i) {
        if (s[i - 1] == '0')
            if (vs[i].size() == 2) {
                uni(c[vs[i][0]], c[vs[i][1]], type[vs[i][0]] == type[vs[i][1]]);
            } else {
                int x = c[vs[i][0]];
                ans -= cost(x);
                fix[x] = type[vs[i][0]];
                ans += cost(x);
            } else if (s[i - 1] == '1')
                if (vs[i].size() == 2) {
                    uni(c[vs[i][0]], c[vs[i][1]], type[vs[i][0]] != type[vs[i][1]]);
                } else if (vs[i].size() == 1) {
                    int x = c[vs[i][0]];
                    ans -= cost(x);
                    fix[x] = 1 - type[vs[i][0]];
                    ans += cost(x);
                }
        cout << ans << ' ';
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
        solve();
}