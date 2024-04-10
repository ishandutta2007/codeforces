#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

llint tc, n, t, a, b;
int tip[MAXN], p[MAXN];
vector <int> v[2], r;

int check (int val, int nxt) {
    int cnta = upper_bound(v[0].begin(), v[0].end(), val) - v[0].begin();
    int cntb = upper_bound(v[1].begin(), v[1].end(), val) - v[1].begin();
    int res = cnta + cntb;
    llint d = cnta * a + cntb * b;
    if (d > nxt) return 0;
    llint ost = nxt - d;
    res += min((llint) v[0].size() - cnta, ost / a);
    ost -= min((llint) v[0].size() - cnta, ost / a) * a;
    res += min((llint) v[1].size() - cntb, ost / b);
    ost -= min((llint) v[1].size() - cntb, ost / b) * b;
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;
    while (tc--) {
        v[0].clear(); v[1].clear(); r.clear();
        cin >> n >> t >> a >> b;
        for (int i = 0; i < n; i++) cin >> tip[i];
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            v[tip[i]].push_back(p[i]);
            r.push_back(p[i]);
        }
        sort(v[0].begin(), v[0].end());
        sort(v[1].begin(), v[1].end());
        r.push_back(0); r.push_back(t + 1);
        sort(r.begin(), r.end());
        r.erase(unique(r.begin(), r.end()), r.end());
        int res = 0;
        for (int i = 0; i < (int) r.size() - 1; i++) {
            res = max(res, check(r[i], r[i + 1] - 1));
        }
        cout << res << '\n';
    }
    return 0;
}