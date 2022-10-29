// Long Live The King
#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int M[N], e, vr;
vector < int > Adj[N];
void DFS(int v)
{
    M[v] = 1;
    for (int u : Adj[v])
        if (!M[u]) DFS(u);
    e += (int)Adj[v].size();
    vr ++;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0, x, y; i < k; i ++)
        scanf("%d%d", &x, &y), Adj[x].push_back(y), Adj[y].push_back(x);
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (!M[i] && Adj[i].size())
        {
            DFS(i);
            cnt += e / 2 - vr + 1;
            e = vr = 0;
        }
    return !printf("%d\n", cnt);
}