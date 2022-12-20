#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int mod = 998244353;

vector <pair<int, pair<int, int> > > v;
vector <int> t[N];
int num[N];
bool is[N];


void uni(int a, int b) {
    if (t[a].size() < t[b].size())
        swap(a, b);
    for (int i = 0; i < t[b].size(); ++i) {
        num[t[b][i]] = a;
        t[a].push_back(t[b][i]);
    }
    is[a] = is[a] || is[b];
}

int main() {
    int i, j, n, m, k, a, b, c;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (i = 1; i <= k; ++i) {
        cin >> j;
        is[j] = true;
    }
    for (i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    for (i = 1; i <= n; ++i) {
        num[i] = i;
        t[i].push_back(i);
    }
    int ans = 0;
    for (i = 0; i < m; ++i)
    if (num[v[i].se.fi] != num[v[i].se.se]) {
        if (is[num[v[i].se.fi]] && is[num[v[i].se.se]]) {
            ans = max(ans, v[i].fi);
        }
        uni(num[v[i].se.fi], num[v[i].se.se]);
    }
    for (i = 1; i <= k; ++i)
        cout << ans << ' ';
}