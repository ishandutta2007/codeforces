//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
typedef long long ll;
typedef long double ld;

const int M = 1e5 + 239;
const int BIG = 1e9 + 239;

vector<pair<int, int>> v[M];
int n, m;
int s[M], c[M], ans[M];

vector<int> now;

void dfs(int p)
{
    now.push_back(p);
    for (auto [i, w] : v[p])
        if (s[i] == 0)
        {
            s[i] = -s[p];
            c[i] = w - c[p];
            dfs(i);
        }
}

int main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, f, w;
        cin >> s >> f >> w;
        s--, f--;
        w *= 2;
        v[s].push_back(make_pair(f, w));
        v[f].push_back(make_pair(s, w));
    }
    for (int i = 0; i < n; i++)
        if (s[i] == 0)
        {
            now.clear();
            s[i] = 1;
            c[i] = 0;
            dfs(i);
            int mn = BIG;
            int mx = -BIG;
            for (int t : now)
                for (auto [p, w] : v[t])
                {
                    if (s[p] != s[t])
                    {
                        if (c[p] + c[t] != w)
                        {
                            cout << "NO\n";
                            return 0;
                        }
                        continue;
                    }
                    int cur = (w - c[p] - c[t]) / (2 * s[p]);
                    mn = min(mn, cur);
                    mx = max(mx, cur);
                }
            if (mn == BIG)
            {
                vector<int> cd;
                for (int t : now)
                    cd.push_back(-s[t] * c[t]);
                sort(cd.begin(), cd.end());
                int cur = cd[(int)cd.size() / 2];
                for (int t : now)
                    ans[t] = s[t] * cur + c[t];
                continue;
            }
            if (mn != mx)
            {
                cout << "NO\n";
                return 0;
            }
            for (int t : now)
                ans[t] = s[t] * mn + c[t];
        }
    cout << "YES\n";
    cout << fixed << setprecision(1);
    for (int i = 0; i < n; i++)
        cout << ans[i] / 2.0 << " ";
    cout << "\n";
    return 0;
}