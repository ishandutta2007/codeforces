#include <bits/stdc++.h>

using namespace std;

int check(vector<int> deg)
{
    sort(deg.rbegin(), deg.rend());
    int tot = 0;
    for (int i = 0; i + 1 < deg.size(); i++)
    {
        tot += deg[i];
        if (tot == i * (i + 1) / 2 + (i + 1) * (deg.size() - i - 1))
            return 0;
    }
    return 1;
}

int check1(vector<string> &s)
{
    vector<int> deg(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (s[i][j] == '1')
                deg[i]++;
        }
    }
    return check(deg);
}

void invert(vector<string> &s, int v)
{
    for (int i = 0; i < s.size(); i++)
    {
        s[i][v] = '1' + '0' - s[i][v];
        s[v][i] = '1' + '0' - s[v][i];
    }
}

void invert(vector<string> &s, int v, vector<int> &deg)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (i == v) continue;
        if (s[i][v] == '1')
        {
            deg[i]--;
            deg[v]++;
            s[i][v] = '0';
            s[v][i] = '1';
        }
        else
        {
            deg[i]++;
            deg[v]--;
            s[i][v] = '1';
            s[v][i] = '0';
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    if (check1(s))
    {
        cout << "0 1";
        return 0;
    }
    if (n < 9)
    {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        vector<vector<int> > ans;
        int cnt = n + 1;
        while (1)
        {
            int cur = n - 1;
            for (int i = 0; i < n; i++)
            {
                invert(s, p[i]);
                if (check1(s))
                {
                    cur = i;
                    if (cur + 1 < cnt)
                    {
                        cnt = cur + 1;
                        ans.clear();
                    }
                    if (cur + 1 == cnt)
                    {
                        vector<int> q;
                        for (int j = 0; j <= i; j++) q.push_back(p[i]);
                        ans.push_back(q);
                    }
                    break;
                }
            }
            for (int i = cur; i >= 0; i--)
            {
                invert(s, p[i]);
            }
            if (!next_permutation(p.begin(), p.end()))
                break;
        }
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        if (ans.size() == 0)
        {
            cout << -1;
            return 0;
        }
        cout << cnt << " " << ans.size() << endl;
        return 0;
    }
    int ans = 0;
    vector<int> deg(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == '1')
            {
                deg[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        invert(s, i, deg);
        if (check(deg)) ans++;
        invert(s, i, deg);
    }
    cout << 1 << " " << ans << endl;
}