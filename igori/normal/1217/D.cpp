#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>
 
using namespace std;
 
int n, m;
int a[5100], b[5100];
 
vector<int> graph[5100];
 
int ans[5010];
 
int In[2100000];
int Out[2100000];
int T = 1;
int color[2100000];
int visit = 0;
 
int k = 0;
 
void dfs(int v)
{
    color[v] = 1;
    In[v] = T++;
    for (auto i : graph[v])
    {
        int u = a[i] + b[i] - v;
        if (color[u] == 0)
        {
            dfs(u);
        }
        if (color[u] == 1)
        {
            k = 2;
        }
    }
    color[v] = 2;
    visit++;
    Out[v] = T++;
}
 
int id[5010];
 
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        graph[a[i]].push_back(i);
        //graph[b[i]].push_back(i);
    }
    k = 1;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            dfs(i);
        }
    }
    cout << k << endl;
    if (k == 1)
    {
        for (int i = 0; i < m;  i++) cout << 1 << " ";
        return 0;
    }
    vector<pair<int, int> > TopSort;
    for (int i = 1; i <= n; i++)
    {
        TopSort.push_back({-Out[i], i});
    }
    sort(TopSort.begin(), TopSort.end());
    for (int i = 0; i < n; i++)
    {
        id[TopSort[i].second] = i;
    }
    for (int i = 0; i < m; i++)
    {
        if (id[a[i]] < id[b[i]])
            cout << 1 << " ";
        else
            cout << 2 << " ";
    }
}