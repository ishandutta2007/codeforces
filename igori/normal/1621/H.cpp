#include <bits/stdc++.h>
 
using namespace std;
 
const long long INF = 1e9 + 5;
 
void dfs(int v, int par, vector<vector<pair<int, int> > > &g,
         vector<int> &p, vector<long long> &depth,
         string &z, vector<int> &checkpoint, int T, int k,
         vector<vector<long long> > &table_total,
         vector<vector<pair<int, int> > > &table_changes)
{
    checkpoint[v] = checkpoint[par];
 
    p[v] = par;
 
    if (z[par] != z[v])
    {
        checkpoint[v] = par;
 
        if (table_total[par].empty())
        {
            int vv = par;
            long long enter_time = 0;
            long long cur_time = 0;
 
            vector<pair<int, int> > changes;
            vector<long long> total(k);
 
            while (vv != 0)
            {
                cur_time += depth[vv] - depth[checkpoint[vv]];
                int L = enter_time % T, R = (cur_time - 1) % T;
 
                total[z[vv] - 'A'] += (cur_time - 1 + T) / T - (enter_time - 1 + T) / T;
 
                L = (T - L) % T;
                R = (T - R) % T;
                if ((L + 1) % T != R % T)
                {
                    if (R % T != 0) changes.push_back({R % T, z[vv]});
                    if ((L + 1) % T != 0) changes.push_back({(L + 1) % T, -z[vv]});
                }
 
                enter_time = cur_time;
                vv = checkpoint[vv];
            }
 
            sort(changes.begin(), changes.end());
 
            table_total[checkpoint[v]] = total;
            table_changes[checkpoint[v]] = changes;
        }
    }
 
    for (auto e : g[v]) if (e.first != par)
    {
        depth[e.first] = depth[v] + e.second;
        dfs(e.first, v, g, p, depth, z, checkpoint, T, k, table_total, table_changes);
    }
}
 
void dfs(int v, int p, vector<vector<pair<int, int> > > &g, string &z,
         vector<int> &checkpoint_sector, vector<vector<int> > &have_such_checkpoint_sector)
{
    if (z[v] != 'A') have_such_checkpoint_sector[v][checkpoint_sector[v]] = 1;
    for (auto e : g[v]) if (e.first != p)
    {
        dfs(e.first, v, g, z, checkpoint_sector, have_such_checkpoint_sector);
        if (z[e.first] == z[v] && z[v] != 'A')
        {
            for (int i = 0; i < have_such_checkpoint_sector[e.first].size(); i++)
                if (have_such_checkpoint_sector[e.first][i] == 1)
                    have_such_checkpoint_sector[v][i] = 1;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    // read the main input
    int n;
    cin >> n;
    vector<vector<pair<int, int> > > g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int v, u, t;
        cin >> v >> u >> t;
        v--, u--;
        g[v].push_back({u, t});
        g[u].push_back({v, t});
    }
 
    int k;
    cin >> k;
    string z;
    cin >> z;
 
    vector<int> pass(k), fine(k);
    for (int i = 0; i < k; i++)
    {
        cin >> pass[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> fine[i];
    }
 
    int T;
    cin >> T;
 
    // work with main data
    vector<int> p(n);
    vector<long long> depth(n);
    vector<int> checkpoint(n);
    vector<vector<long long> > table_total(n);
    vector<vector<pair<int, int> > > table_changes(n);
    dfs(0, 0, g, p, depth, z, checkpoint, T, k, table_total, table_changes);
 
    vector<int> checkpoint_sector(n);
    for (int i = 0; i < n; i++)
    {
        if (z[i] == 'A') continue;
        int CH = checkpoint[i];
        int pass = (depth[i] - depth[CH]) % T;
        for (int j = 0; j < table_changes[CH].size(); j++)
        {
            if (table_changes[CH][j].first <= pass)
                checkpoint_sector[i]++;
        }
    }
    vector<vector<int> > have_such_checkpoint_sectors(n, vector<int>(2 * k + 1));
    dfs(0, 0, g, z, checkpoint_sector, have_such_checkpoint_sectors);
 
    // answer queries
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            char z;
            int c;
            cin >> z >> c;
            pass[z - 'A'] = c;
            continue;
        }
        else if (t == 2)
        {
            char z;
            int c;
            cin >> z >> c;
            fine[z - 'A'] = c;
            continue;
        }
        int u;
        cin >> u;
        u--;
 
        if (z[u] == 'A')
        {
            cout << 0 << "\n";
            continue;
        }
        int CH = checkpoint[u];
        long long ans = 1e18;
        vector<long long> total = table_total[CH];
        long long cur = 0;
        for (int i = 0; i < k; i++) cur += min(1ll * pass[i], 1ll * fine[i] * min(total[i], INF));
        for (int i = 0; i <= table_changes[CH].size(); i++)
        {
            if (have_such_checkpoint_sectors[u][i]) ans = min(ans, cur);
            if (i == table_changes[CH].size()) break;
            int j = table_changes[CH][i].second;
            if (j > 0)
            {
                j -= 'A';
                cur -= min(1ll * pass[j], 1ll * fine[j] * min(total[j], INF));
                total[j]++;
                cur += min(1ll * pass[j], 1ll * fine[j] * min(total[j], INF));
            }
            else
            {
                j *= -1;
                j -= 'A';
                cur -= min(1ll * pass[j], 1ll * fine[j] * min(total[j], INF));
                total[j]--;
                cur += min(1ll * pass[j], 1ll * fine[j] * min(total[j], INF));
            }
        }
        cout << ans << "\n";
    }
}