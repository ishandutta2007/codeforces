// Ponies everywhere ...
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, C[2];
vector < int > Adj[N];
void DFS(int v, int p = 0, int h = 0)
{
    C[h & 1] ++;
    for (int u : Adj[v])
        if (u != p)
            DFS(u, v, h + 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i ++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        Adj[v].push_back(u);
        Adj[u].push_back(v);
    }
    DFS(1);
    return !printf("%d\n", min(C[0], C[1]) - 1);
}