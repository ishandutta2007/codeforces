#include <iostream>
#include <vector>

using namespace std;

#define prev prevfff

int n, r1, r2;
vector<int> graph[500000];

int prev[500000];

void dfs(int v, int p)
{
    if (prev[v] != 0) return;
    prev[v] = p;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int u = graph[v][i];
        dfs(u, v);
    }
}

int main()
{
    cin >> n >> r1 >> r2;
    int j = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (j == r1) j++;
        int a;
        cin >> a;
        graph[a].push_back(j);
        graph[j].push_back(a);
        j++;
    }
    dfs(r2, -1);
    for (int i = 1; i <= n; i++)
    {
        if (prev[i] != -1)
            cout << prev[i] << " ";
    }
}