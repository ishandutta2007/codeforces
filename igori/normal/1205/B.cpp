#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

long long n;
long long a[500000];
long long cntb[500000];

vector<int> graph[500000];
vector<pair<int, int> > edges;

long long dist[500000];

long long no(int x, int y, int x2, int y2)
{
    if (x == x2 && y == y2) return 0;
    if (y == x2 && x == y2) return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int b = 0; b < 62; b++)
    {
        for (int i = 0; i < n; i++)
            if (a[i] & (1LL << b))
                cntb[b]++;
        if (cntb[b] >= 3)
        {
            cout << 3;
            return 0;
        }
    }
    for (int b = 0; b < 62; b++)
    {
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            if (a[i] & (1LL << b))
            {
                nums.push_back(i);
            }
        }
        if (nums.size() == 2)
        {
            graph[nums[0]].push_back(nums[1]);
            graph[nums[1]].push_back(nums[0]);
            edges.push_back({nums[0], nums[1]});
        }
    }
    long long ans = 1e9;
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < n; j++) dist[j] = -1;
        dist[edges[i].first] = 0;
        vector<int> q = {edges[i].first};
        for (int j = 0; j < q.size(); j++)
        {
            int v = q[j];
            for (auto u : graph[v])
            {
                if (dist[u] == -1 && no(v, u, edges[i].first, edges[i].second))
                {
                    dist[u] = dist[v] + 1;
                    q.push_back(u);
                }
            }
        }
        if (dist[edges[i].second] != -1) ans = min(ans, dist[edges[i].second] + 1);
    }
    if (ans == 1e9)
    {
        cout << -1;
        return 0;
    }
    cout << ans;
}