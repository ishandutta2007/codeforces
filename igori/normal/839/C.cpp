#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> g[500000];
int mark[500000];
double ans[500000];

int nextInt()
{
    int y = 0;
    char c = getchar();
    while ('0' <= c && c <= '9')
    {
        y = 10 * y + c - '0';
        c = getchar();
    }
    return y;
}

void dfs(int v)
{
   mark[v] = 1;
   double summ = 0, iq = 0;
   for (auto u : g[v])
   {
       if (mark[u] == 0)
       {
           dfs(u);
           summ += ans[u] + 1;
           iq++;
       }
   }
   if (iq == 0) ans[v] = 0;
   else ans[v] = summ / iq;
}

int main()
{
    n = nextInt();
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int v, u;
        v = nextInt(), u = nextInt();
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1);
    printf("%.9f", ans[1]);
}