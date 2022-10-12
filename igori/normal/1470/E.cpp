#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cnt(int len, int coins)
{
    ll ans = 0;
    if (0 <= coins && 0 <= len) ans += 1;
    if (1 <= coins && 1 <= len) ans += len - 1;
    if (2 <= coins && 2 <= len) ans += 1ll * (len - 1) * (len - 2) / 2;
    if (3 <= coins && 3 <= len) ans += 1ll * (len - 1) * (len - 2) * (len - 3) / 6;
    if (4 <= coins && 4 <= len) ans += 1ll * (len - 1) * (len - 2) * (len - 3) * (len - 4) / 24;
    return ans;
}

void solve()
{
    int n, c, q;
    cin >> n >> c >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i], p[i]--;

    struct Segment{
        int rL, rR;
        long long len, plen;
    };

    vector<deque<Segment> > s(c + 1);

    for (int coins = 0; coins <= c; coins++)
    {
        s[coins].push_back({n, n, 1});
        for (int i = n - 2; i >= 0; i--)
        {
            int me = p[i];
            vector<pair<int, int> > le, ri;
            for (int j = i + 1; j <= i + coins && j < n; j++)
            {
                if (p[j] < me)
                {
                    le.push_back({p[j], j});
                }
                else
                {
                    ri.push_back({p[j], j});
                }
            }
            sort(le.begin(), le.end());
            reverse(le.begin(), le.end());
            sort(ri.begin(), ri.end());
            for (int j = 0; j < le.size(); j++)
            {
                s[coins].push_front({i, le[j].second, cnt(n - 1 - le[j].second, coins - le[j].second + i)});
            }
            for (int j = 0; j < ri.size(); j++)
            {
                s[coins].push_back({i, ri[j].second, cnt(n - 1 - ri[j].second, coins - ri[j].second + i)});
            }
        }
        for (int i = 0; i < s[coins].size(); i++)
        {
            s[coins][i].plen = s[coins][i].len + (i ? s[coins][i - 1].plen : 0);
        }
    }
    const long long INFLL = 1e18 + 2222;
    vector<vector<long long> > go(c + 1, vector<long long>(n + 1, INFLL));
    for (int coins = 0; coins <= c; coins++)
    {
        for (int j = (int)s[coins].size() - 1; j >= 0; j--)
        {
            go[coins][s[coins][j].rL] = min(go[coins][s[coins][j].rL], s[coins][j].plen - s[coins][j].len);
        }
    }
    for (int coins = 0; coins <= c; coins++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            go[coins][j] = min(go[coins][j], go[coins][j + 1]);
        }
    }
    vector<int> answer(q, -2);
    struct Ask{
        long long j;
        int i, id;
    };
    vector<vector<Ask> > asks(c + 1);
    for (int ii = 0; ii < q; ii++)
    {
        long long j;
        int i;
        cin >> i >> j;
        i--, j--;
        if (j >= cnt(n, c))
        {
            answer[ii] = -1;
            continue;
        }
        asks[c].push_back({j, i, ii});
    }
    for (int level = c; level >= 0; level--)
    {
        sort(asks[level].begin(), asks[level].end(), [&](Ask A, Ask B){
             return A.j < B.j;
             });
        int pnt = 0;
        for (auto e : asks[level])
        {
            while (pnt + 1 < s[level].size() && s[level][pnt].plen <= e.j)
                pnt++;
            int L = s[level][pnt].rL;
            int R = s[level][pnt].rR;
            if (e.i <= R)
            {
                if (L <= e.i)
                    answer[e.id] = p[L + R - e.i] + 1;
                else
                    answer[e.id] = p[e.i] + 1;
            }
            else
            {
                int NL = level - (R - L);
                asks[NL].push_back({e.j - s[level][pnt].plen + s[level][pnt].len + go[NL][R + 1], e.i, e.id});
            }
        }
        vector<Ask> z;
        swap(asks[level], z);
    }
    for (int i = 0; i < q; i++)
    {
        cout << answer[i] << "\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}