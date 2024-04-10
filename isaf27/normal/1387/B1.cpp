//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
typedef long long ll;
typedef long double ld;

const int M = 1e5 + 239;
const int BIG = 1e9 + 239;

vector<int> v[M];
int n, dp[M][2];
vector<int> v1[M];
vector<int> v2[M];

void dfs(int p, int pr)
{
    if (v[p].size() == 1 && pr != -1)
    {
        dp[p][0] = BIG;
        dp[p][1] = 0;
        return;
    }
    for (int i : v[p])
        if (i != pr)
            dfs(i, p);
    dp[p][1] = 0;
    for (int i : v[p])
        if (i != pr)
        {
            if (dp[i][0] == BIG)
            {
                dp[p][1] = BIG;
                break;
            }
            dp[p][1] += dp[i][0];
        }
    vector<pair<int, int>> val;
    ll cur = 0;
    for (int i : v[p])
        if (i != pr)
        {
            val.push_back(make_pair(min(dp[i][0], dp[i][1]) + 1 - dp[i][0], i));
            cur += dp[i][0];
        }
    sort(val.begin(), val.end());
    int it = 0;
    while (it < val.size() && val[it].first < 0)
    {
        cur += val[it].first;
        it++;
    }
    if (it == 0)
    {
        cur += val[it].first;
        it++;
    }
    dp[p][0] = cur;
    for (int i = 0; i < it; i++)
        v1[p].push_back(val[i].second);
    for (int i = it; i < val.size(); i++)
        v2[p].push_back(val[i].second);
}

vector<int> g[M];

void make(int p, int pr, int need)
{
    //cerr << p << " " << pr << " " << need << "!\n";
    if (need == 0)
    {
        for (int i : v[p])
            if (i != pr)
                make(i, p, 1);
        return;
    }
    for (int i : v1[p])
    {
        //cerr << i + 1 << " " << p + 1 << "\n";
        g[p].push_back(i);
        g[i].push_back(p);
        if (dp[i][0] <= dp[i][1])
            make(i, p, 1);
        else
            make(i, p, 0);
    }
    for (int i : v2[p])
        make(i, p, 1);
}

vector<int> et;

void dfs_et(int p, int pr)
{
    et.push_back(p);
    for (int i : g[p])
        if (i != pr)
            dfs_et(i, p);
}

int ans[M];

int main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    dfs(0, -1);
    cout << 2 * dp[0][0] << "\n";
    make(0, -1, 1);
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; i++)
        if (ans[i] == -1)
        {
            et.clear();
            dfs_et(i, -1);
            for (int t = 0; t < (int)et.size(); t++)
                ans[et[t]] = et[(t + 1) % (int)et.size()];
        }
    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    cout << "\n";
    return 0;
}