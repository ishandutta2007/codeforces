#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int BIG = 1e9 + 1;
const int XX = 1e4 + 1;
const ld pi = acos(-1.0);
const int M = 2 * 1e5 + 1;

int n;
vector<string> s;

void over()
{
    cout << "NO";
    exit(0);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    cin.sync_with_stdio(0);
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int len = 0;
    for (int i = 0; i < n; i++)
        len += s[i].size();
    for (int i = 0; i < n; i++)
    {
        if (s[i].size() > 26)
            over();
        for (int x = 0; x < s[i].size(); x++)
            for (int y = x + 1; y < s[i].size(); y++)
                if (s[i][x] == s[i][y])
                    over();
    }
    for (char x = 'a'; x <= 'z'; x++)
    {
        vector<vector<string> > now(len);
        vector<string> nw;
        for (int i = 0; i < s.size(); i++)
        {
            int pos = -1;
            for (int w = 0; w < s[i].size(); w++)
                if (s[i][w] == x)
                {
                    pos = w;
                    break;
                }
            if (pos == -1)
                nw.push_back(s[i]);
            else
                now[pos].push_back(s[i]);
        }
        string t = "";
        int pos = -1;
        for (int i = len - 1; i >= 0; i--)
        {
            for (string u : now[i])
            {
                if (pos == -1)
                {
                    pos = i;
                    t = u;
                    continue;
                }
                for (int j = 0; j < i; j++)
                    if (t[pos + j - i] != u[j])
                        over();
                for (int j = i; j < u.size(); j++)
                {
                    if (pos + j - i >= t.size())
                        t += u[j];
                    if (t[pos + j - i] != u[j])
                        over();
                }
            }
        }
        if (t.empty())
            continue;
        if (t.size() > 26)
            over();
        for (int x = 0; x < t.size(); x++)
            for (int y = x + 1; y < t.size(); y++)
                if (t[x] == t[y])
                    over();
        nw.push_back(t);
        s = nw;
    }
    sort(s.begin(), s.end());
    for (string t : s)
        cout << t;
    return 0;
}