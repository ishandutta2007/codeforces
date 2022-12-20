#include <bits/stdc++.h>
#define fi first
#define se second
#define sqr(a) ((a) * (a))
#define ll long long
#define ld lond double
using namespace std;
const int N = 1e5 + 1;
const int inf = 1e9 + 1;

map <int, int> m;
map <int, vector <int> > t;
int p[N], s[N];
bool b[N];

int main() {
    int i, j, k, n, x, l, r, u;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> u >> k;
    for (i = 1; i <= n; ++i)
        cin >> p[i];
    for (j = 1; j <= n; ++j)
        cin >> s[j];
    for (j = 1; j <= n; ++j) {
        cin >> i;
        b[i] = 1;
    }
    for (i = 1; i <= n; ++i)
    if (!b[i])
        m[s[i]] = max(m[s[i]], p[i]);
    else
        t[s[i]].push_back(p[i]);
    int ans = 0;
    for (map<int, vector <int> >:: iterator it = t.begin(); it != t.end(); ++it) {
        bool is = 0;
        for (j = 0; j < (*it).second.size(); ++j)
        if ((*it).second[j] >= m[(*it).first])
            is = 1;
        ans += (*it).second.size() - is;
    }
    cout << ans;

}