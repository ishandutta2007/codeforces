#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(v) (v).begin(), (v).end()

int cx[4] = {0, 0, 1, -1};
int cy[4] = {-1, 1, 0, 0};

bool dfs(int v, int &T, vvi &g, vi &vis, vi &mt)
{
    if (vis[v] == T) return false;
    vis[v] = T;
    for (auto u : g[v])
    {
        if (mt[u] == -1 || dfs(mt[u], T, g, vis, mt))
        {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi A(n, vi(m));
    vi L, R;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
            if ((i + j) % 2 == 0) L.push_back(i * m + j);
            else R.push_back(i * m + j);
        }
    }
    vi bad(n * m, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = i + cx[k], ny = j + cy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && A[nx][ny] < A[i][j])
                    bad[i * m + j] = 0;
            }
        }
    }
    vvi g(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = i + cx[k], ny = j + cy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && A[nx][ny] == A[i][j])
                    g[i * m + j].push_back(nx * m + ny);
            }
        }
    }
    int ok = 1, T = 1;
    vi vis(n * m), mt(n * m);
    auto pairing = [&](vi L, vi R){
        vi use(n * m);
        for (auto v : R)
            use[v] = 1, mt[v] = -1;
        for (auto v : L)
        {
            vi act;
            for (auto u : g[v]) if (use[u]) act.push_back(u);
            g[v] = act;
        }
        sort(all(L), [&](int v, int u){
                return bad[v] > bad[u];
             });
        vi res;
        for (auto v : L)
        {
            if (dfs(v, T, g, vis, mt)) res.push_back(v);
            else if (bad[v]) ok = 0;
            T++;
        }
        return res;
    };
    vi x = pairing(L, R);
    vi y = pairing(R, x);
    if (!ok) cout << "NO\n";
    else
    {
        cout << "YES\n";
        string D = "LRDU";
        vector<string> dir(n, string(m, '.'));
        vector<vector<int> > num(n, vector<int>(m));
        for (auto f : x)
        {
            int t = mt[f];
            if (t == f - 1) dir[f / m][f % m] = 'L', dir[t / m][t % m] = 'R';
            if (t == f + 1) dir[f / m][f % m] = 'R', dir[t / m][t % m] = 'L';
            if (t == f - m) dir[f / m][f % m] = 'U', dir[t / m][t % m] = 'D';
            if (t == f + m) dir[f / m][f % m] = 'D', dir[t / m][t % m] = 'U';
            assert(A[f / m][f % m] == A[t / m][t % m]);
            num[f / m][f % m] = A[f / m][f % m] - 1;
            num[t / m][t % m] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (num[i][j] == 0)
                {
                    assert(bad[i * m + j] == 0);
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + cx[k], ny = j + cy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < m && A[nx][ny] < A[i][j])
                            num[i][j] = A[i][j] - A[nx][ny], dir[i][j] = D[k];
                    }
                }
                cout << num[i][j] << " \n"[j + 1 == m];
            }
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << dir[i][j] << " \n"[j + 1 == m];
            }
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}