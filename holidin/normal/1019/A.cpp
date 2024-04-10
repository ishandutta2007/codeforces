#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 4000;

map <int, int> m;
vector <int> v[N];
vector <pair<int, int> > v1;
long long c[N], ans, a[N], p;

int main() {
    int i, j, i1, n, k;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        cin >> a[i] >> p;
        if (a[i] == 1)
            p = 0;
        v[a[i]].push_back(p);
        ++m[p];
    }
    for (map <int, int> :: iterator it = m.begin(); it != m.end(); ++it)
        v1.push_back({(*it).first, (*it).second});
    for (i = 1; i <= k; ++i)
        sort(v[i].begin(), v[i].end());
    long long minans = 1e18 + 1;
    for (i = 1; i <= n; ++i) {
        long long ans = 0, cnt = 0;
        for (j = 0; j < v1.size(); ++j)
            c[j] = v1[j].second;
        for (j = 1; j <= k; ++j)
        for (i1 = 0; v[j].size() - i1 >= i; ++i1) {
            int l = 0, r = v1.size();
            while (r - l > 1) {
                int x = (l + r) >> 1;
                if (v1[x].first > v[j][i1])
                    r = x;
                else
                    l = x;
            }
            ++cnt;
            ans += v[j][i1];
            --c[l];
        }
        int i1 = 0;
        for (j = cnt; j < i; ++j) {
            while (c[i1] == 0) ++i1;
            ans += v1[i1].first;
            --c[i1];
        }
        minans = min(minans, ans);
    }
    cout << minans;
}