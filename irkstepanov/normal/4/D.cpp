#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

struct env
{
    int w, h, n;
};

bool comp (env a, env b)
{
    ll s1 = (ll) (a.w) * (ll) (a.h);
    ll s2 = (ll) (b.w) * (ll) (b.h);
    return s1 < s2;
}

int main()
{

    int n, w, h;
    cin >> n >> w >> h;

    vector <env> m;
    for (int i = 0; i < n; i++)
    {
        env tmp;
        cin >> tmp.w >> tmp.h;
        if (tmp.w <= w || tmp.h <= h) continue;
        tmp.n = i + 1;
        m.pb(tmp);
    }

    env tmp;
    tmp.w = w, tmp.h = h, tmp.n = 0;
    m.pb(tmp);

    vector <int> dp(n + 1), pr(n + 1);

    sort (m.begin(), m.end(), comp);

    /*for (int i = 0; i < m.size(); i++)
        cout << m[i].n << " ";*/

    for (int i = 1; i < m.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] + 1 > dp[i] && m[i].w > m[j].w && m[i].h > m[j].h)
            {
                dp[i] = dp[j] + 1;
                pr[i] = j;
            }
        }
    }

    int ans = -1, pos;
    for (int i = 0; i < m.size(); i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            pos = i;
        }
    }

    cout << ans << "\n";
    vector <int> otv;
    while (pos)
    {
        otv.pb(m[pos].n);
        pos = pr[pos];
    }
    for (int i = (int) otv.size() - 1; i >= 0; i--)
        cout << otv[i] << " ";

}