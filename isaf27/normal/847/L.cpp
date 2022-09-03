#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll p = 239;
const int M = 1001;

int n;
ll st[M], al;
vector<vector<ll> > h;
vector<vector<vector<int> > > str;
vector<vector<int> > v;
vector<int> now;
bool used[M];

void dfs(int p)
{
    used[p] = true;
    for (int i : v[p])
        if (!used[i])
            dfs(i);
}

void dfs_se(int p)
{
    now.push_back(p);
    used[p] = true;
    for (int i : v[p])
        if (!used[i])
            dfs_se(i);
}

int32_t main()
{
    //freopen("test.in", "r", stdin);
    cin.sync_with_stdio(0);
    cin >> n;
    h.resize(n);
    str.resize(n);
    st[0] = 1;
    for (int i = 0; i < n; i++)
        st[i + 1] = (st[i] * p) % MOD;
    al = 0;
    for (int i = 0; i < n; i++)
        al = (al + st[i]) % MOD;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int pos = 0;
        while (pos < s.size())
        {
            int k = 0;
            while (isdigit(s[pos]))
                k = 10 * k + (s[pos] - '0'), pos++;
            ll hs = 0;
            vector<int> nw;
            for (int t = 0; t < k; t++)
            {
                pos++;
                int num = 0;
                while (isdigit(s[pos]))
                    num = 10 * num + (s[pos] - '0'), pos++;
                num--;
                nw.push_back(num);
                hs = (hs + st[num]) % MOD;
            }
            str[i].push_back(nw);
            h[i].push_back(hs);
            if (pos != s.size())
                pos++;
        }
    }
    map<ll, vector<int> > pos;
    for (int i = 0; i < n; i++)
        for (ll x : h[i])
            pos[x].push_back(i);
    int kol = 0;
    for (int i = 0; i < n; i++)
        for (ll x : h[i])
        {
            ll an = (al - x) % MOD;
            if (an < 0) an += MOD;
            if (pos.find(an) == pos.end())
                continue;
            kol += pos[an].size();
        }
    if (kol != 2 * n - 2)
    {
        cout << -1;
        return 0;
    }
    vector<pair<int, int> > r;
    for (int i = 0; i < n; i++)
        for (ll x : h[i])
        {
            ll an = (al - x) % MOD;
            if (an < 0) an += MOD;
            for (int j : pos[an])
                if (j > i)
                    r.push_back(make_pair(i, j));
        }
    if (r.size() != n - 1)
    {
        cout << -1;
        return 0;
    }
    v.resize(n);
    for (pair<int, int> t : r)
    {
        v[t.first].push_back(t.second);
        v[t.second].push_back(t.first);
    }
    memset(used, 0, sizeof(used));
    dfs(0);
    for (int i = 0; i < n; i++)
        if (!used[i])
        {
            cout << -1;
            return 0;
        }
    for (int i = 0; i < n; i++)
    {
        memset(used, 0, sizeof(used));
        used[i] = true;
        vector<vector<int> > c;
        for (int x : v[i])
        {
            now.clear();
            dfs_se(x);
            sort(now.begin(), now.end());
            c.push_back(now);
        }
        sort(c.begin(), c.end());
        for (int x = 0; x < str[i].size(); x++)
            sort(str[i][x].begin(), str[i][x].end());
        sort(str[i].begin(), str[i].end());
        if (c != str[i])
        {
            cout << -1;
            return 0;
        }
    }
    cout << r.size() << "\n";
    for (pair<int, int> t : r)
        cout << t.first + 1 << " " << t.second + 1 << "\n";
    return 0;
}