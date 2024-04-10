#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <random>
#include <fstream>

using namespace std;

const int N = 500000;

int n;
vector<int> graph[N];
int ans = 0;
int dp[N][2];
int par[N];

void dfs(int v, int p)
{
    par[v] = p;
    vector<pair<int, int> > a, b;
    int cnt = 0;
    for (auto u : graph[v]) if (u != p)
    {
        dfs(u, v);
        a.push_back({dp[u][0], u});
        b.push_back({dp[u][1], u});
        cnt++;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int mx0 = 0, mx1 = 0;
    if (cnt >= 1)
    {
        mx0 = max(mx0, a[0].first);
        mx1 = max(mx1, b[0].first);
    }
    dp[v][0] = mx1 + 1;
    dp[v][1] = max(0, cnt - 1) + max(mx0, mx1);
    ans = max(ans, dp[v][0]);
    ans = max(ans, dp[v][1] + (p != 0));
    if (cnt >= 2)
    {
        ans = max(ans, b[0].first + b[1].first + 1);
        int omega = 0;
        omega = max(a[0].first + a[1].first, b[0].first + b[1].first);
        omega = max(omega, max(a[0].first + b[1].first, a[1].first + b[0].first));
        if (a[0].second != b[0].second) omega = max(omega, a[0].first + b[0].first);
        ans = max(ans, omega + cnt - 2 + (p != 0));
    }
}

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) ans = max(ans, (int)graph[i].size());
    dfs(1, 0);
    cout << ans;
}