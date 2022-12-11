/**honest prim for o(n ^ 3)**/

#include <bits/stdc++.h>

#define x first
#define y second

#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <int, int> edge;

const int inf = 1000000000;

int main()
{

    int w, h, n, c;
    cin >> h >> w >> n >> c;

    vector <vector <string> > table(n, vector <string> (h));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < h; j++)
        cin >> table[i][j];

    vector <vector <int> > m(n + 1, vector <int> (n + 1));
    for (int u = 0; u <= n; u++)
        for (int v = 0; v <= n; v++)
    {
        if (u == v) continue;
        if (!u) m[u][v] = h * w;
        else if (!v) m[u][v] = h * w;
        else
        {
            int kol = 0;
            for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++)
                kol += (table[u - 1][i][j] != table[v - 1][i][j]);
            m[u][v] = c * kol;
        }
    }

    vector <edge> ans;
    vector <int> met(n + 1);
    vector <int> good(n + 1);

    met[0] = 1;
    int total = 0;

    for (int step = 1; step <= n; step++)
    {
        int cost = inf, vertex;
        for (int u = 0; u <= n; u++)
            if (!met[u] && m[u][good[u]] < cost)
        {
            cost = m[u][good[u]];
            vertex = u;
        }
        total += m[good[vertex]][vertex];
        ans.pb(mp(vertex, good[vertex]));
        met[vertex] = 1;
        for (int u = 0; u <= n; u++)
            if (!met[u] && m[u][vertex] < m[u][good[u]])
                good[u] = vertex;
    }

    cout << total << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].x << " " << ans[i].y << "\n";

}