#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int eu[N * 3] , ev[N * 3];
int pt[N * 2];
vector<int> edge[N * 2];
map<pair<int , int> , int> mp;
vector<int> order;
bool visited[N * 2] , used[N * 3];
char ans[N];

void dfs(int u)
{
    visited[u] = true;
    while(pt[u] < edge[u].size())
    {
        int e = edge[u][pt[u]++];
        int v = eu[e] ^ ev[e] ^ u;

        if (used[e]) continue;

        used[e] = true;
        dfs(v);
    }
    order.push_back(u);
}

int main()
{
    // freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> eu[i] >> ev[i];
        ev[i] += (int)2e5 + 3;

        edge[eu[i]].push_back(i);
        edge[ev[i]].push_back(i);
        mp[{eu[i] , ev[i]}] = mp[{ev[i] , eu[i]}] = i;
    }

    int m = n;
    for (int i = 1 ; i < N * 2 - 2 ; ++i)
    {
        if (edge[i].size() & 1)
        {
            ++m;

            if (i <= n)
            {
                eu[m] = i;
                ev[m] = N * 2 - 1;
            }
            else
            {
                eu[m] = i;
                ev[m] = N * 2 - 2;
            }

            edge[eu[m]].push_back(m);
            edge[ev[m]].push_back(m);
        }
    }

    // for (int i = 1 ; i <= m ; ++i) cout << eu[i] << " " << ev[i] << "\n";
    // return 0;

    memset(visited , 0 , sizeof(visited));
    if (edge[N * 2 - 1].size() & 1)dfs(N * 2 - 1);
    if (edge[N * 2 - 2].size() & 1 && !visited[N * 2 - 2]) dfs(N * 2 - 2);
    for (int i = 1 ; i < N * 2 - 2 ; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    // for (int x : order) cout << x << " ";
    // cout << "\n";

    for (int i = 0 ; i < order.size() - 1 ; ++i)
    {
        int u = order[i];
        int v = order[i + 1];
        if (mp.find({u , v}) != mp.end()) ans[mp[{u , v}]] = (i & 1 ? 'r' : 'b');
    }

    for (int i = 1 ; i <= n ; ++i) cout << ans[i];
    cout << "\n";
}