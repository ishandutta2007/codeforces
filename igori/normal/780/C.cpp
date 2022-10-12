#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <time.h>
//
using namespace std;
//
#define int long long
//
int n;
vector<int> graph[500000];
int ans[500000];
int k;
//
int p[500000];
//
void go(int v, int p)
{
    int c = -1;
    if (p != -1)
    {
        c = ans[p];
    }
    if (ans[v] == 0)
        ans[v] = 1;
    int r = 1;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int x = graph[v][i];
        if (ans[x] == 0)
        {
            if (r == ans[v])
                r++;
            if (r == c)
                r++;
            if (r == ans[v])
                r++;
            ans[x] = r;
            r++;
            go(x, v);
        }
    }
}
//
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
        k = max((long long)graph[x].size() + 1, k);
        k = max((long long)graph[y].size() + 1, k);
    }
    cout << k << endl;
    go(0, -1);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}