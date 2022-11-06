#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int main()
{
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    
    char levels[k + 1][n + 1][m + 1];
    
    for (int i = 1; i <= k; i += 1)
    {
        for (int j = 0; j < n; j += 1)
        {
            cin >> levels[i][j];
        }
    }
    
    int graph[k + 1][k + 1];
    
    for (int i = 1; i <= k; i += 1)
    {
        graph[0][i] = graph[i][0] = n * m;
        for (int j = 1; j <= k; j += 1)
        {
            int diff = 0;
            for (int y = 0; y < n; y += 1)
                for (int x = 0; x < m; x += 1)
                {
                    if (levels[i][y][x] != levels[j][y][x]) diff += 1;
                }
            
            graph[i][j] = graph[j][i] = w * diff;
        }
    }
    
    int number = 0;
    
    vector< pair<int, int> > result;
    int used[k + 1];
    #define p pair<int, pair<int, int> >
    priority_queue<p, vector<p>, greater<p> > q;
    #undef p
    
    
    for (int i = 0; i <= k; i += 1)
    {
        used[i] = 0;
        q.push(make_pair(graph[0][i], make_pair(0, i)));
    }
    used[0] = 1;
    
    while (!q.empty())
    {
        pair<int, int> edge = q.top().second;
        q.pop();
        if (!used[edge.second])
        {
            number += graph[edge.first][edge.second];
            result.push_back(edge);
            int new_v = edge.second;
            used[new_v] = 1;
            for (int i = 0; i <= k; i += 1)
            {
                if (!used[i])
                    q.push(make_pair(graph[new_v][i], make_pair(new_v, i)));
            }
        }
    }
    
    cout << number << endl;
    for (int i = 0; i < result.size(); i += 1)
    {
        cout << result[i].second << ' ' << result[i].first << endl;
    }
}