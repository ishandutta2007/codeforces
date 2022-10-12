#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)

void dfs(int v, vi &col, vi &ts, vvi &g)
{
    col[v] = 1;
    for (auto u : g[v]) if (col[u] == 0)
    {
        dfs(u, col, ts, g);
    }
    ts.push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int> > g(n);
    vi in(n);
    vector<vector<int> > con(n, vector<int>(n));
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        con[a][b] = 1;
        in[b]++;
    }
    vector<int> ts, col(n);
    forn(i, n)
    {
        if (in[i] == 0 && !col[i])
        {
            dfs(i, col, ts, g);
        }
    }
    struct edit{
        char c;
        int fr, to;
    };
    vector<edit> edits;
    int b = min(n, 16);
    for (int i = 0; i < b; i++)
    {
        for (int j = i + 1; j < b; j++)
        {
            int fr = ts[j], to = ts[i];
            if (!con[fr][to])
            {
                con[fr][to] = 1;
                edits.push_back({'+', fr + 1, to + 1});
            }
        }
    }
    for (int i = b; i < n; i++)
    {
        int v = ts[i];
        edits.push_back({'+', v + 1, v + 1});
    }
    vector<int> have(1 << b, -1);
    for (int i = b; i < n; i++)
    {
        int v = ts[i];
        int mask = 0;
        for (int j = 0; j < b; j++)
        {
            if (con[v][ts[j]])
                mask += (1 << j);
        }
        int t = 0;
        for (int edit = 0; !t && edit <= b; edit++)
        {
            vector<int> e(b);
            for (int j = b - 1; j >= b - edit; j--)
                e[j] = 1;
            while (!t)
            {
                int mask2 = mask;
                for (int j = 0; j < b; j++)
                {
                    if (e[j]) mask2 ^= (1 << j);
                }
                if (have[mask2] == -1)
                {
                    t = 1;
                    have[mask2] = v;
                    for (int j = 0; j < b; j++)
                    {
                        if (e[j] && (mask & (1 << j)))
                        {
                            edits.push_back({'-', v + 1, ts[j] + 1});
                            con[v][ts[j]] = 0;
                        }
                        if (e[j] && !(mask & (1 << j)))
                        {
                            edits.push_back({'+', v + 1, ts[j] + 1});
                            con[v][ts[j]] = 1;
                        }
                    }
                }
                if (!next_permutation(e.begin(), e.end()))
                    break;
            }
        }
    }
    cout << edits.size() << "\n";
    for (auto e : edits)
    {
        cout << e.c << " " << e.fr << " " << e.to << "\n";
    }
    cout << endl;
    while (t--)
    {
        vector<string> res(b);
        for (int j = 0; j < b; j++)
        {
            cout << "? 1 " << ts[j] + 1 << "\n";
        }
        cout << endl;
        int mask = 0, fail = -1;
        for (int j = 0; j < b; j++)
        {
            cin >> res[j];
            if (res[j] == "Lose")
            {
                assert(fail == -1);
                fail = ts[j];
            }
            else
            {
                if (res[j] == "Win")
                {
                    mask += (1 << j);
                }
            }
        }
        if (fail != -1)
        {
            cout << "! " << fail + 1 << endl;
            string s;
            cin >> s;
            continue;
        }
        cout << "! " << have[mask] + 1 << endl;
        string s;
        cin >> s;
    }
}