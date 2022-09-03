#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e18;

const int MAXN = 251;
const int BF = 30;
const int BIG = 1e9 + 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, p, qq;
string s[MAXN];
int dist[MAXN][MAXN];

bool check(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

ll fnd(int x, int y)
{
    if (s[x][y] == '*')
        return 0;
    ll ans = 0;
    for (int i = x - BF; i <= x + BF; i++)
        for (int j = y - BF; j <= y + BF; j++)
            if (check(i, j))
                dist[i][j] = BIG;
    dist[x][y] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        int gx = t.first;
        int gy = t.second;
        if (dist[gx][gy] == BF)
            continue;
        for (int d = 0; d < 4; d++)
        {
            int nx = gx + dx[d];
            int ny = gy + dy[d];
            if (!check(nx, ny))
                continue;
            if (s[nx][ny] == '*')
                continue;
            if (dist[nx][ny] > dist[gx][gy] + 1)
            {
                dist[nx][ny] = dist[gx][gy] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    for (int i = x - BF; i <= x + BF; i++)
        for (int j = y - BF; j <= y + BF; j++)
            if (check(i, j) && 'A' <= s[i][j] && s[i][j] <= 'Z' && dist[i][j] < BF)
                ans += ((s[i][j] - 'A' + 1) * qq) / (1 << dist[i][j]);
    return ans;
}

int32_t main()
{
    #define fname "test"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout); /**/
    cin >> n >> m >> qq >> p;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int ans = 0;
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cerr << fnd(i, j) << " ";
        cerr << "\n";
    }*/
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (fnd(i, j) > p)
                ans++;
    cout << ans;
    return 0;
}